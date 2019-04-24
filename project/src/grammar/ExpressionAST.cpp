#include "grammar/ExpressionAST.hpp"
using namespace Intr;
ExpressionAST& ExpressionAST::operator+=(ExpressionAST const& rhs)
{
    expr = BinaryOp('+', expr, rhs);
    return *this;
}

ExpressionAST& ExpressionAST::operator-=(ExpressionAST const& rhs)
{
    expr = BinaryOp('-', expr, rhs);
    return *this;
}

ExpressionAST& ExpressionAST::operator*=(ExpressionAST const& rhs)
{
    expr = BinaryOp('*', expr, rhs);
    return *this;
}

ExpressionAST& ExpressionAST::operator/=(ExpressionAST const& rhs)
{
    expr = BinaryOp('/', expr, rhs);
    return *this;
}

boost::phoenix::function<NegateExpr> neg;

