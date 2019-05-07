#include "ast/ExpressionAST.hpp"
#include "lexer/helper/LexerIdToString.hpp"
#include <iostream>
using namespace Intr;
ExpressionAST::ExpressionAST()
    : m_expression(Nil()) {}

ExpressionAST &ExpressionAST::binaryOperation(const ExpressionAST &right, Lexer::Id operation)
{
    m_expression = BinaryOperation(operation, m_expression, right);
    return *this;
}

BinaryOperation::BinaryOperation(BinaryOperation::Type op, const ExpressionAST &left, const ExpressionAST &right)
    : m_op(op), m_left(left), m_right(right) {}

UnaryOperation::UnaryOperation(UnaryOperation::Type op, const ExpressionAST &subject)
    : m_op(op), m_subject(subject) {}


ExpressionAST &Detail::CreateNegativeNode(ExpressionAST &leftExpression, const ExpressionAST &rightExpression)
{
    return leftExpression = ExpressionAST(UnaryOperation(Lexer::ID_SUBTRACTION, rightExpression));
}

ExpressionAST &Detail::CreateBinaryNode(ExpressionAST &leftExpression, const ExpressionAST &rightExpression, Lexer::Id operation)
{
    return leftExpression.binaryOperation(rightExpression, operation);
}

ExpressionAST &Detail::CreateIdentifire(ExpressionAST &leftExpression, const std::string &name)
{
    return leftExpression = Identifier(name);
}
