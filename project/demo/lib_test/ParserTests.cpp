
#include "grammar/ExpressionGrammar.hpp"
#include "grammar/LiteralGrammar.hpp"
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
using unary_op = UnaryOperation;
using binary_op = BinaryOperation;
using expression_ast = ExpressionAST;
struct ast_print
    {
        typedef void result_type;

        void operator()(Nil) const {}
        void operator()(int n) const { std::cout << n; }

        void operator()(expression_ast const& ast) const
        {
            boost::apply_visitor(*this, ast.m_expression);
        }

        void operator()(binary_op const& expr) const
        {
            std::cout << "op:" << expr.op << "(";
            boost::apply_visitor(*this, expr.left.m_expression);
            std::cout << ", ";
            boost::apply_visitor(*this, expr.right.m_expression);
            std::cout << ')';
        }

        void operator()(unary_op const& expr) const
        {
            std::cout << "op:" << expr.op << "(";
            boost::apply_visitor(*this, expr.subject.m_expression);
            std::cout << ')';
        }
    };
int main()
{
    std::string str = "2";
    Intr::Lexer lexerFunctor;
    Intr::ExpressionGrammar exprGrammar(lexerFunctor);
    auto begin = std::begin(str);
    ExpressionAST val;
    Intr::lex::tokenize_and_parse(begin, std::end(str), lexerFunctor, exprGrammar, val);
    boost::apply_visitor(ast_print(), val.m_expression);
    return 0;
}
