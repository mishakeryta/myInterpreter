#include "lexer/Lexer.hpp"

using namespace Intr;


Lexer::Lexer()
{
    using boost::phoenix::ref;
    using boost::phoenix::construct;
    using boost::spirit::_1;

    using lex::_start;
    using lex::_end;

    intNumber = lex::token_def<std::int32_t>("(\\+|\\-)?\\d+", ID_INT_NUMBER);
    ifStatement = lex::token_def<>("if", ID_IF_STATEMENT);
    whileStatement = lex::token_def<>("while", ID_WHILE_STATEMENT);
    scopeBegin = lex::token_def<>("\\{", ID_SCOPE_BEGIN);
    scopeEnd = lex::token_def<>("\\}", ID_SCOPE_END);
    identifier = lex::token_def <std::string> ("[_a-zA-Z][_a-zA-Z0-9]*", ID_IDENTIFIER);
    any = lex::token_def <std::string>(".", ID_ANY);

    this->self = intNumber | ifStatement | whileStatement | scopeBegin | scopeEnd | identifier | any;
}
