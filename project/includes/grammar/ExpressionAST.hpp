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
       using Type = boost::variant<
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

        const Type& expression() const { return m_expression; }

    private:
        Type m_expression;
    };

    namespace Detail
    {
        template<class Expr>
        ExpressionAST &CreateRegularNode(ExpressionAST &leftExpression, const Expr &rightExpression)
        {
            return leftExpression = rightExpression;
        }

        ExpressionAST &CreateNegativeNode(ExpressionAST &leftExpression, const ExpressionAST &rightExpression);

        ExpressionAST &CreateAdditionNode(ExpressionAST &leftExpression, const ExpressionAST &rightExpression);

        ExpressionAST &CreateSubtractionNode(ExpressionAST &leftExpression, const ExpressionAST &rightExpression);

        ExpressionAST &CreateMultiplicationNode(ExpressionAST &leftExpression, const ExpressionAST &rightExpression);

        ExpressionAST &CreateDivisionNode(ExpressionAST &leftExpression, const ExpressionAST &rightExpression);

    };
//FIXME: Need to uncomment all of them , but only in process of finishing ExpressionGrammar
    BOOST_PHOENIX_ADAPT_FUNCTION(ExpressionAST &, CreateRegularNode, Detail::CreateRegularNode, 2);
    BOOST_PHOENIX_ADAPT_FUNCTION(ExpressionAST &, CreateNegativeNode, Detail::CreateNegativeNode, 2);
    BOOST_PHOENIX_ADAPT_FUNCTION(ExpressionAST &, CreateAdditionNode, Detail::CreateAdditionNode, 2);
    BOOST_PHOENIX_ADAPT_FUNCTION(ExpressionAST &, CreateSubtractionNode, Detail::CreateSubtractionNode, 2);
    BOOST_PHOENIX_ADAPT_FUNCTION(ExpressionAST &, CreateMultiplicationNode, Detail::CreateMultiplicationNode, 2);
    BOOST_PHOENIX_ADAPT_FUNCTION(ExpressionAST &, CreateDivisionNode, Detail::CreateDivisionNode, 2);

    class BinaryOperation
    {
    public:
        using Type = Lexer::Id;

        BinaryOperation(Type op, const ExpressionAST &left, const ExpressionAST &right);

        Type operatrion() const { return m_op; }
        const ExpressionAST &left() const { return m_left; }
        const ExpressionAST &right() const { return m_right; }

    private:
        Type m_op;
        ExpressionAST m_left;
        ExpressionAST m_right;
    };

    class UnaryOperation
    {
    public:
        using Type = Lexer::Id;

        UnaryOperation(Type op, const ExpressionAST& subject);

        Type operation() const { return m_op; }
        const ExpressionAST &subject() const { return m_subject; }

    private:
        Type m_op;
        ExpressionAST m_subject;
    };
};
#endif // EXPRESSIONAST_HPP
