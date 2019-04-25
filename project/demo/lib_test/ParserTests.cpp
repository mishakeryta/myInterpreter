#include "grammar/ExpressionAST.hpp"
#include "grammar/ExpressionGrammar.hpp"
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
    std::string str = "asds2";
    Intr::Lexer lexerFunctor;
    Intr::ExpressionGrammar exprGrammar;
    auto begin = std::begin(str);
    Intr::lex::tokenize_and_parse(begin, std::end(str), lexerFunctor, exprGrammar);
    return 0;
}
