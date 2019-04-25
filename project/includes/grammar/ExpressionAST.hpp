#ifndef EXPRESSIONAST_HPP
#define EXPRESSIONAST_HPP

#include "lexer/Lexer.hpp"

#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/variant/recursive_variant.hpp>
#include <boost/variant/apply_visitor.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/phoenix_function.hpp>

#include <boost/phoenix/function/adapt_function.hpp>

#include <memory>

namespace Intr
{
    class BinaryOperation;
    class UnaryOperation;
    class Nil {};



    class ExpressionAST
    {
    public:
       using type = boost::variant<
                Nil // can't happen!
              , int
              , boost::recursive_wrapper<ExpressionAST>
              , boost::recursive_wrapper<BinaryOperation>
              , boost::recursive_wrapper<UnaryOperation>
            >;


        ExpressionAST();

        template <typename Expr>
        ExpressionAST(const Expr &expr)
          : m_expression(expr) {}

        ExpressionAST &addition(const ExpressionAST &rightExpression);
        ExpressionAST &subtraction(const ExpressionAST &rightExpression);
        ExpressionAST &multiplication(const ExpressionAST &rightExpression);
        ExpressionAST &division(const ExpressionAST &rightExpression);


        type m_expression;
    };

    namespace Detail
    {
        template<class Expr>
        ExpressionAST &CreateRegularNode(ExpressionAST &leftExpression, const Expr &rightExpression)
        {
            return leftExpression = rightExpression;
        }

        ExpressionAST &CreateAdditionNode(ExpressionAST &leftExpression, const ExpressionAST &rightExpression)
        {
            return leftExpression.addition(rightExpression);
        }

        ExpressionAST &CreateSubtractionNode(ExpressionAST &leftExpression, const ExpressionAST &rightExpression)
        {
            return leftExpression.subtraction(rightExpression);
        }

        ExpressionAST &CreateMultiplicationNode(ExpressionAST &leftExpression, const ExpressionAST &rightExpression)
        {
            return leftExpression.multiplication(rightExpression);
        }

        ExpressionAST &CreateDivisionNode(ExpressionAST &leftExpression, const ExpressionAST &rightExpression)
        {
            return leftExpression.division(rightExpression);
        }

    };

    BOOST_PHOENIX_ADAPT_FUNCTION(ExpressionAST &, CreateRegularNode, Detail::CreateAdditionNode, 2);
    BOOST_PHOENIX_ADAPT_FUNCTION(ExpressionAST &, CreateAdditionNode, Detail::CreateAdditionNode, 2);
    BOOST_PHOENIX_ADAPT_FUNCTION(ExpressionAST &, CreateSubtractionNode, Detail::CreateAdditionNode, 2);
    BOOST_PHOENIX_ADAPT_FUNCTION(ExpressionAST &, CreateMultiplicationNode, Detail::CreateAdditionNode, 2);
    BOOST_PHOENIX_ADAPT_FUNCTION(ExpressionAST &, CreateDivisionNode, Detail::CreateAdditionNode, 2);

    class BinaryOperation
    {
    public:
        using Type = Lexer::Id;
        BinaryOperation(
            Type op
          , ExpressionAST const& left
          , ExpressionAST const& right);

        Type op;
        ExpressionAST left;
        ExpressionAST right;
    };

    class UnaryOperation
    {
    public:
        using Type = Lexer::Id;
        UnaryOperation(
            Type op
          , ExpressionAST const& subject);

        Type op;
        ExpressionAST subject;
    };

    class NegateExpression
    {
    public:
        template <typename T>
        struct result { typedef T type; };

        ExpressionAST operator()(ExpressionAST const& expr) const;
    };
};
#endif // EXPRESSIONAST_HPP
