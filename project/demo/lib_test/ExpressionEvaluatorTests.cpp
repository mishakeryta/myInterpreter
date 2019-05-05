#include "grammar/ExpressionGrammar.hpp"
#include "grammar/LiteralGrammar.hpp"
#include "ast/helper/ExpressionASTPrinter.hpp"
#include "evaluator/ExpressionEvaluator.hpp"


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

int main()
{
    std::string str = "\"44\"==\"44\"";
    Intr::Lexer lexerFunctor;
    Intr::ExpressionGrammar exprGrammar(lexerFunctor);
    auto itr = std::begin(str);
    auto begin = lexerFunctor.begin(itr, str.end());
    auto end = lexerFunctor.end();
    ExpressionAST ast;
    Intr::qi::phrase_parse(begin, end, exprGrammar, Intr::qi::in_state("skip")[lexerFunctor.self], ast);

    boost::apply_visitor(Helper::ExpressionASTPrinter(std::cout), ast.expression());

    std::cout << boost::apply_visitor(ExpressionEvaluator(), ast.expression());


    return 0;
}
