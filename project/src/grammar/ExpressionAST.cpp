#include "grammar/ExpressionAST.hpp"

using namespace Intr;
ExpressionAST::ExpressionAST()
    : expr(Nil()) {}

ExpressionAST& ExpressionAST::addition(const ExpressionAST &rightValue)
{
    expr = BinaryOp(Lexer::ID_ADDITION, expr, rightValue);
    return *this;
}

ExpressionAST& ExpressionAST::subtraction(const ExpressionAST &rightValue)
{
    expr = BinaryOp(Lexer::ID_SUBTRACTION, expr, rightValue);
    return *this;
}

ExpressionAST& ExpressionAST::multiplication(const ExpressionAST &rightValue)
{
    expr = BinaryOp(Lexer::ID_MULTIPLICATION, expr, rightValue);
    return *this;
}

ExpressionAST& ExpressionAST::division(const ExpressionAST& rightValue)
{
    expr = BinaryOp(Lexer::ID_DIVISION, expr, rightValue);
    return *this;
}



BinaryOp::BinaryOp(BinaryOp::Type op, const ExpressionAST &left, const ExpressionAST &right)
    : op(op), left(left), right(right) {}

UnaryOp::UnaryOp(UnaryOp::Type op, const ExpressionAST &subject)
    : op(op), subject(subject) {}

static boost::phoenix::function<NegateExpr> neg;

ExpressionAST NegateExpr::operator()(const ExpressionAST &expr) const
{
    return ExpressionAST(UnaryOp(Lexer::ID_SUBTRACTION, expr));
}

