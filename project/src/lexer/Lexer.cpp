#include "lexer/Lexer.hpp"

using namespace Intr;


Lexer::Lexer()
{
    intNumber = lex::token_def<std::int32_t>("(\\+|\\-)?\\d+", ID_INT_NUMBER);
    ifStatement = lex::token_def<>("if", ID_IF_STATEMENT);
    whileStatement = lex::token_def<>("while", ID_WHILE_STATEMENT);
    scopeBegin = lex::token_def<>("\\{", ID_SCOPE_BEGIN);
    scopeEnd = lex::token_def<>("\\}", ID_SCOPE_END);
    parenthesisBegin = lex::token_def<>("\\(", ID_PARENTHESIS_BEGIN);
    parenthesisEnd = lex::token_def<>("\\)", ID_PARENTHESIS_END);
    identifier = lex::token_def <std::string> ("[_a-zA-Z][_a-zA-Z0-9]*", ID_IDENTIFIER);
    any = lex::token_def <std::string>(".", ID_ANY);

    //order is important due to mutually exclusive regex
    //for example number could be a part of indetifier
    this->self = intNumber | ifStatement |  whileStatement | scopeBegin | scopeEnd | parenthesisBegin | parenthesisEnd | identifier | any;
}
