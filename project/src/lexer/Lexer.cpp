#include "lexer/Lexer.hpp"

using namespace Intr;

Lexer::Lexer()
{
    //some of it require modifications
    //https://stackoverflow.com/questions/13395453/how-to-combine-boostspiritlex-boostspiritqi
    doubleNumber = lex::token_def<double>("\\d+\\.\\d+", ID_DOUBLE_NUMBER);
    intNumber = lex::token_def<std::int32_t>("\\d+", ID_INT_NUMBER);

    ifStatement = lex::token_def<>("if", ID_IF_STATEMENT);
    whileStatement = lex::token_def<>("while", ID_WHILE_STATEMENT);

    scopeBegin = lex::token_def<>("\\{", ID_SCOPE_BEGIN);
    scopeEnd = lex::token_def<>("\\}", ID_SCOPE_END);

    parenthesisBegin = lex::token_def<>("\\(", ID_PARENTHESIS_BEGIN);
    parenthesisEnd = lex::token_def<>("\\)", ID_PARENTHESIS_END);

    statementEnd = lex::token_def<>(";", ID_STATEMENT_END);

    addition = lex::token_def<>("\\+", ID_ADDITION);
    subtraction = lex::token_def<>("\\-", ID_SUBTRACTION);

    multiplication = lex::token_def<>("\\*", ID_MULTIPLICATION);
    division = lex::token_def<>("\\/", ID_DIVISION);

    assignment = lex::token_def<>("=", ID_ASSIGNMENT);
    equality = lex::token_def<>("==", ID_EQUALITY);

    identifier = lex::token_def <std::string> ("[_a-zA-Z][_a-zA-Z0-9]*", ID_IDENTIFIER);
    any = lex::token_def <std::string>(".", ID_ANY);

    //order is important due to mutually exclusive regex
    //for example number could be a part of indetifier
    this->self = doubleNumber |intNumber |
            ifStatement |  whileStatement |
            scopeBegin | scopeEnd |
            parenthesisBegin | parenthesisEnd |
            statementEnd |
            assignment | equality |
            addition | subtraction |
            multiplication | division |
            identifier | any;
}
