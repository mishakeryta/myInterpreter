#include "grammar/ExpressionGrammar.hpp"
#include "grammar/LiteralGrammar.hpp"
#include "grammar/helper/ExpressionASTPrinter.hpp"

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



int main()
{
    std::string str = "2+(3*2)";
    Intr::Lexer lexerFunctor;
    Intr::ExpressionGrammar exprGrammar(lexerFunctor);
    auto begin = std::begin(str);
    ExpressionAST val;
    Intr::lex::tokenize_and_parse(begin, std::end(str), lexerFunctor, exprGrammar, val);
    std::cout << (begin == std::end(str));
    boost::apply_visitor(Helper::ExpressionASTPrinter(), val.expression());
    return 0;
}
