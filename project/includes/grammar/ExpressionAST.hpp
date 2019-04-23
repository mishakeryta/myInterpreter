#ifndef EXPRESSIONAST_HPP
#define EXPRESSIONAST_HPP

#include "lexer/Lexer.hpp"

#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/variant/recursive_variant.hpp>
#include <boost/variant/apply_visitor.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/phoenix_function.hpp>
#include <boost/test/utils/named_params.hpp>

#include <memory>

namespace Intr
{
    class BinaryOperation;
    class UnaryOperation;
    class Nil {};

    class ExpressionAST
    {
        using ExpressionType =
            boost::variant<
                Nil // can't happen!
              , unsigned int
              , boost::recursive_wrapper<ExpressionAST>
              , boost::recursive_wrapper<BinaryOperation>
              , boost::recursive_wrapper<UnaryOperation>
            >;
    public:
        ExpressionAST();

        template <typename Expr>
        ExpressionAST(const Expr &expr)
          : m_expression(expr) {}

        ExpressionAST& addition(const ExpressionAST &rightExpression);
        ExpressionAST& subtraction(const ExpressionAST &rightExpression);
        ExpressionAST& multiplication(const ExpressionAST &rightExpression);
        ExpressionAST& division(const ExpressionAST &rightExpression);


        ExpressionType m_expression;
    };

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
