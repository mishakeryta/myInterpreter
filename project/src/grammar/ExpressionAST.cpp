#include "grammar/ExpressionAST.hpp"

using namespace Intr;
ExpressionAST::ExpressionAST()
    : m_expression(Nil()) {}

ExpressionAST& ExpressionAST::addition(const ExpressionAST &right)
{
    m_expression = BinaryOperation(Lexer::ID_ADDITION, m_expression, right);
    return *this;
}

ExpressionAST& ExpressionAST::subtraction(const ExpressionAST &right)
{
    m_expression = BinaryOperation(Lexer::ID_SUBTRACTION, m_expression, right);
    return *this;
}

ExpressionAST& ExpressionAST::multiplication(const ExpressionAST &right)
{
    m_expression = BinaryOperation(Lexer::ID_MULTIPLICATION, m_expression, right);
    return *this;
}

ExpressionAST& ExpressionAST::division(const ExpressionAST& right)
{
    m_expression = BinaryOperation(Lexer::ID_DIVISION, m_expression, right);
    return *this;
}



BinaryOperation::BinaryOperation(BinaryOperation::Type op, const ExpressionAST &left, const ExpressionAST &right)
    : op(op), left(left), right(right) {}

UnaryOperation::UnaryOperation(UnaryOperation::Type op, const ExpressionAST &subject)
    : op(op), subject(subject) {}

static boost::phoenix::function<NegateExpression> neg;

ExpressionAST NegateExpression::operator()(const ExpressionAST &expr) const
{
    return ExpressionAST(UnaryOperation(Lexer::ID_SUBTRACTION, expr));
}


//ExpressionAST &Detail::CreateRegularNode(ExpressionAST &leftExpression, const ExpressionAST &rightExpression)
//{
//    return leftExpression = rightExpression;
//}

//ExpressionAST &Detail::CreateAdditionNode(ExpressionAST &leftExpression, const ExpressionAST &rightExpression)
//{
//    return leftExpression.addition(rightExpression);
//}

//ExpressionAST &Detail::CreateSubtractionNode(ExpressionAST &leftExpression, const ExpressionAST &rightExpression)
//{
//    return leftExpression.subtraction(rightExpression);
//}

//ExpressionAST &Detail::CreateMultiplicationNode(ExpressionAST &leftExpression, const ExpressionAST &rightExpression)
//{
//    return leftExpression.multiplication(rightExpression);
//}

//ExpressionAST &Detail::CreateDivisionNode(ExpressionAST &leftExpression, const ExpressionAST &rightExpression)
//{
//    return leftExpression.division(rightExpression);
//}

