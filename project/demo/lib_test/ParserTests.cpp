#include "grammar/ExpressionGrammar.hpp"
#include "grammar/LiteralGrammar.hpp"
#include "lexer/Helper.hpp"
#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/variant/recursive_variant.hpp>
#include <boost/variant/apply_visitor.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/phoenix_function.hpp>
#include <boost/test/utils/named_params.hpp>

#include <iostream>
#include <vector>
#include <string>

using namespace Intr;
using UnaryOperation = UnaryOperation;


struct ast_print
    {
        typedef void result_type;

        void operator()(Nil) const {}
        void operator()(int n) const { std::cout << n; }

        void operator()(const ExpressionAST &ast) const
        {
            boost::apply_visitor(*this, ast.expression());
        }

        void operator()(const BinaryOperation &expr) const
        {
            std::cout << "op:" << LexerIdToString(expr.operatrion()) << "(";
            boost::apply_visitor(*this, expr.left().expression());
            std::cout << ", ";
            boost::apply_visitor(*this, expr.right().expression());
            std::cout << ')';
        }

        void operator()(UnaryOperation &expr) const
        {
            std::cout << "op:" << LexerIdToString(expr.operation()) << "(";
            boost::apply_visitor(*this, expr.subject().expression());
            std::cout << ')';
        }
    };

int main()
{
    std::string str = "2+(3*2)";
    Intr::Lexer lexerFunctor;
    Intr::ExpressionGrammar exprGrammar(lexerFunctor);
    auto begin = std::begin(str);
    ExpressionAST val;
    Intr::lex::tokenize_and_parse(begin, std::end(str), lexerFunctor, exprGrammar, val);
    std::cout << (begin == std::end(str));
    boost::apply_visitor(ast_print(), val.expression());
    return 0;
}
