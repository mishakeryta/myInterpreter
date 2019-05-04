#include "lexer/helper/LexerIdToString.hpp"
#include "ast/helper/ExpressionASTPrinter.hpp"
#include "ast/ExpressionAST.hpp"

#include <boost/variant/apply_visitor.hpp>

#include <iostream>

using namespace Intr;

Helper::ExpressionASTPrinter::ExpressionASTPrinter(std::ostream& out)
    :m_out(out)
{}

void Helper::ExpressionASTPrinter::operator()(const Intr::ExpressionAST &ast) const
{
    boost::apply_visitor(*this, ast.expression());
}

void Helper::ExpressionASTPrinter::operator()(const Intr::BinaryOperation &binary) const
{
    std::cout << "op:" << LexerIdToString(binary.operatrion()) << '(';
    boost::apply_visitor(*this, binary.left().expression());
    std::cout << ", ";
    boost::apply_visitor(*this, binary.right().expression());
    std::cout << ')';
}

void Helper::ExpressionASTPrinter::operator()(Intr::UnaryOperation &unary) const
{
    std::cout << "op:" << Helper::LexerIdToString(unary.operation()) << "(";
    boost::apply_visitor(*this, unary.subject().expression());
    std::cout << ')';
}

