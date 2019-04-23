#include "grammar/ExpressionGrammar.hpp"
#include <boost/phoenix.hpp>
#include <boost/spirit/include/qi_action.hpp>

#include <iostream>

using namespace Intr;

Parser::Parser() :
    Parser::base_type(start)
{
    start = qi::token(Lexer::ID_IDENTIFIER)[std::cout << qi::_1];
}
