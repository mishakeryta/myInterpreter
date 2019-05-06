#include "lexer/Lexer.hpp"

#include <boost/phoenix/function/function.hpp>
#include <boost/phoenix/object/construct.hpp>

using namespace Intr;

Lexer::Lexer()
{
    using boost::phoenix::construct;
    regexStringLiteral = lex::token_def<std::string>(("R\\\"([^\\\"]|\\.)*\\\""), ID_REGEX_STRING_LITERAL);
    stringLiteral = lex::token_def<std::string>(("\\\"([^\\\"]|\\.)*\\\""), ID_STRING_LITERAL);
    doubleLiteral = lex::token_def<double>("(([1-9][0-9]*)|0{1})(\\.\\d+)", ID_DOUBLE_LITERAL);
    intLiteral = lex::token_def<std::int32_t>("([1-9][0-9]*)|0{1}", ID_INT_LITERAL);
    boolLiteral = lex::token_def<bool>("(false)|(true)", ID_BOOL_LITERAL);

    ifStatement = lex::token_def<lex::omit>("if", ID_IF_STATEMENT);
    elseStatement = lex::token_def<lex::omit>("else", ID_ELSE_STATEMENT);
    whileStatement = lex::token_def<lex::omit>("while", ID_WHILE_STATEMENT);

    scopeBegin = lex::token_def<lex::omit>("\\{", ID_SCOPE_BEGIN);
    scopeEnd = lex::token_def<lex::omit>("\\}", ID_SCOPE_END);

    parenthesisBegin = lex::token_def<lex::omit>("\\(", ID_PARENTHESIS_BEGIN);
    parenthesisEnd = lex::token_def<lex::omit>("\\)", ID_PARENTHESIS_END);

    statementEnd = lex::token_def<lex::omit>(';', ID_STATEMENT_END);


    assignment = lex::token_def<lex::omit>("=", ID_ASSIGNMENT);

    logicalAnd = lex::token_def<lex::omit>("\\&\\&", ID_LOGICAL_AND);
    logicalOr = lex::token_def<lex::omit>("\\|\\|", ID_LOGICAL_OR);

    isGreater = lex::token_def<lex::omit>("<", ID_IS_LESSER);
    isLesser = lex::token_def<lex::omit>(">", ID_IS_GREATER);

    isEqual= lex::token_def<lex::omit>("==", ID_IS_EQUAL);

    addition = lex::token_def<lex::omit>("\\+", ID_ADDITION);
    subtraction = lex::token_def<lex::omit>("\\-", ID_SUBTRACTION);

    multiplication = lex::token_def<lex::omit>("\\*", ID_MULTIPLICATION);
    division = lex::token_def<lex::omit>("\\/", ID_DIVISION);

    print = lex::token_def<lex::omit>("print", ID_PRINT);

    identifier = lex::token_def <std::string> ("[_a-zA-Z][_a-zA-Z0-9]*", ID_IDENTIFIER);

    coma = lex::token_def <lex::omit> (",", ID_COMA);

    whitespace = lex::token_def<lex::omit>("\\s+", ID_WHITESPACE);

    //order is important due to mutually exclusive regex
    //for example number could be a part of indetifier
    this->self =
            regexStringLiteral[lex::_val = construct<std::string>(lex::_start + 2, lex::_end - 2)]|
            stringLiteral[lex::_val = construct<std::string>(lex::_start + 1, lex::_end - 1)]|            
            doubleLiteral |
            intLiteral | boolLiteral |
            ifStatement | elseStatement|  whileStatement |
            scopeBegin | scopeEnd |
            parenthesisBegin | parenthesisEnd |
            statementEnd |
            assignment |
            logicalOr | logicalAnd |
            isGreater | isLesser | isEqual |
            addition | subtraction |
            multiplication | division |
            print |
            identifier | coma | any;

    this->self("skip") = whitespace;
}
