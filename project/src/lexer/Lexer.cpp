#include "lexer/Lexer.hpp"

using namespace Intr;

Lexer::Lexer()
{
    doubleLiteral = lex::token_def<double>("(([1-9][0-9]*)|0{1})(\\.\\d+)", ID_DOUBLE_LITERAL);
    intLiteral = lex::token_def<std::int32_t>("([1-9][0-9]*)|0{1}", ID_INT_LITERAL);
    boolLiteral = lex::token_def<bool>("(false)|(true)", ID_BOOL_LITERAL);

    ifStatement = lex::token_def<>("if", ID_IF_STATEMENT);
    whileStatement = lex::token_def<>("while", ID_WHILE_STATEMENT);

    scopeBegin = lex::token_def<>("\\{", ID_SCOPE_BEGIN);
    scopeEnd = lex::token_def<>("\\}", ID_SCOPE_END);

    parenthesisBegin = lex::token_def<>("\\(", ID_PARENTHESIS_BEGIN);
    parenthesisEnd = lex::token_def<>("\\)", ID_PARENTHESIS_END);

    statementEnd = lex::token_def<>(";", ID_STATEMENT_END);


    assignment = lex::token_def<>("=", ID_ASSIGNMENT);

    logicalAnd = lex::token_def<>("\\&\\&", ID_LOGICAL_AND);
    logicalOr = lex::token_def<>("\\|\\|", ID_LOGICAL_OR);

    isGreater = lex::token_def<>("<", ID_IS_LESSER);
    isLesser = lex::token_def<>(">", ID_IS_GREATER);

    isEqual= lex::token_def<>("==", ID_IS_EQUAL);

    addition = lex::token_def<>("\\+", ID_ADDITION);
    subtraction = lex::token_def<>("\\-", ID_SUBTRACTION);

    multiplication = lex::token_def<>("\\*", ID_MULTIPLICATION);
    division = lex::token_def<>("\\/", ID_DIVISION);

    identifier = lex::token_def <std::string> ("[_a-zA-Z][_a-zA-Z0-9]*", ID_IDENTIFIER);

    whitespace = lex::token_def<>("\\s+", ID_WHITESPACE);

    //order is important due to mutually exclusive regex
    //for example number could be a part of indetifier
    this->self =
            doubleLiteral | intLiteral |
            boolLiteral |
            ifStatement |  whileStatement |
            scopeBegin | scopeEnd |
            parenthesisBegin | parenthesisEnd |
            statementEnd |
            assignment |
            logicalOr | logicalAnd |
            isGreater | isLesser | isEqual |
            addition | subtraction |
            multiplication | division |
            identifier | any;

    this->self("skip") = whitespace;
}
