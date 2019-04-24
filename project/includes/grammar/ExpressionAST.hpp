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

namespace Intr
{
    using OperationType = Lexer::Id;
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
    ExpressionAST()
      : expr(Nil()) {}

    template <typename Expr>
    ExpressionAST(Expr const& expr)
      : expr(expr) {}

    ExpressionAST& operator+=(ExpressionAST const& rhs);
    ExpressionAST& operator-=(ExpressionAST const& rhs);
    ExpressionAST& operator*=(ExpressionAST const& rhs);
    ExpressionAST& operator/=(ExpressionAST const& rhs);

    type expr;
};

class BinaryOp
{
public:
    BinaryOp(
        char op
      , ExpressionAST const& left
      , ExpressionAST const& right)
    : op(op), left(left), right(right) {}

    char op;
    ExpressionAST left;
    ExpressionAST right;
};

class UnaryOp
{
public:
    UnaryOp(
        char op
      , ExpressionAST const& subject)
    : op(op), subject(subject) {}

    char op;
    ExpressionAST subject;
};

class NegateExpr
{
public:
    template <typename T>
    struct result { typedef T type; };

    ExpressionAST operator()(ExpressionAST const& expr) const
    {
        return ExpressionAST(UnaryOp('-', expr));
    }
};
};
#endif // EXPRESSIONAST_HPP
