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
    class BinaryOp;
    class UnaryOp;
    class Nil {};

    class ExpressionAST
    {
        using type =
            boost::variant<
                Nil // can't happen!
              , unsigned int
              , boost::recursive_wrapper<ExpressionAST>
              , boost::recursive_wrapper<BinaryOp>
              , boost::recursive_wrapper<UnaryOp>
            >;
    public:
        ExpressionAST();

        template <typename Expr>
        ExpressionAST(Expr const& expr)
          : expr(expr) {}

        ExpressionAST& addition(const ExpressionAST &rightValue);
        ExpressionAST& subtraction(const ExpressionAST &rightValue);
        ExpressionAST& multiplication(const ExpressionAST &rightValue);
        ExpressionAST& division(const ExpressionAST &rightValue);

        type expr;
    };

    class BinaryOp
    {
    public:
        using Type = Lexer::Id;
        BinaryOp(
            Type op
          , ExpressionAST const& left
          , ExpressionAST const& right);

        Type op;
        ExpressionAST left;
        ExpressionAST right;
    };

    class UnaryOp
    {
    public:
        using Type = Lexer::Id;
        UnaryOp(
            Type op
          , ExpressionAST const& subject);

        Type op;
        ExpressionAST subject;
    };

    class NegateExpr
    {
    public:
        template <typename T>
        struct result { typedef T type; };

        ExpressionAST operator()(ExpressionAST const& expr) const;
    };
};
#endif // EXPRESSIONAST_HPP
