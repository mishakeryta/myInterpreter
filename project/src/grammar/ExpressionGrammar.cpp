#include "grammar/ExpressionGrammar.hpp"
#include <boost/phoenix.hpp>
#include <boost/spirit/include/qi_action.hpp>


#include <iostream>

using namespace Intr;

ExpressionGrammar::ExpressionGrammar() :
    ExpressionGrammar::base_type(start)
{
    auto print = [](auto val1) { std::cout << val1;};
    start = qi::token(Lexer::ID_IDENTIFIER)[print];
}
