#include "lexer/Helper.hpp"
#include "grammar/helper/ExpressionASTPrinter.hpp"
#include "grammar/ExpressionAST.hpp"

#include <boost/variant/apply_visitor.hpp>

#include <iostream>

using namespace Intr;

void Helper::ExpressionASTPrinter::operator()(int n) const { std::cout << n; }

void Helper::ExpressionASTPrinter::operator()(const Intr::ExpressionAST &ast) const
{
    boost::apply_visitor(*this, ast.expression());
}

void Helper::ExpressionASTPrinter::operator()(const Intr::BinaryOperation &expr) const
{
    std::cout << "op:" << LexerIdToString(expr.operatrion()) << "(";
    boost::apply_visitor(*this, expr.left().expression());
    std::cout << ", ";
    boost::apply_visitor(*this, expr.right().expression());
    std::cout << ')';
}

void Helper::ExpressionASTPrinter::operator()(Intr::UnaryOperation &expr) const
{
    std::cout << "op:" << Helper::LexerIdToString(expr.operation()) << "(";
    boost::apply_visitor(*this, expr.subject().expression());
    std::cout << ')';
}

