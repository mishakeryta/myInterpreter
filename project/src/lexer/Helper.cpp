#include "lexer/Helper.hpp"

#define ENUM_TO_CSTR(enum_id) (#enum_id)

std::string Intr::Helper::LexerIdToString(Lexer::id_type id)
{
    using Lexer = Intr::Lexer;

    switch(id) {
    case Lexer::ID_DOUBLE_LITERAL:
        return ENUM_TO_CSTR(Lexer::ID_DOUBLE_LITERAL);
    case Lexer::ID_INT_LITERAL:
        return ENUM_TO_CSTR(Lexer::ID_INT_LITERAL);
    case Lexer::ID_BOOL_LITERAL:
        return ENUM_TO_CSTR(Lexer::ID_BOOL_LITERAL);
    case Lexer::ID_IF_STATEMENT:
        return ENUM_TO_CSTR(Lexer::ID_IF_STATEMENT);
    case Lexer::ID_WHILE_STATEMENT:
        return ENUM_TO_CSTR(Lexer::ID_WHILE_STATEMENT);
    case Lexer::ID_SCOPE_BEGIN:
        return ENUM_TO_CSTR(Lexer::ID_SCOPE_BEGIN);
    case Lexer::ID_SCOPE_END:
        return ENUM_TO_CSTR(Lexer::ID_SCOPE_END);
    case Lexer::ID_PARENTHESIS_BEGIN:
        return ENUM_TO_CSTR(Lexer::ID_PARENTHESIS_BEGIN);
    case Lexer::ID_PARENTHESIS_END:
        return ENUM_TO_CSTR(Lexer::ID_PARENTHESIS_END);
    case Lexer::ID_STATEMENT_END:
        return ENUM_TO_CSTR(Lexer::ID_STATEMENT_END);
    case Lexer::ID_ASSIGNMENT:
        return ENUM_TO_CSTR(Lexer::ID_ASSIGNMENT);
    case Lexer::ID_LOGICAL_OR:
        return ENUM_TO_CSTR(Lexer::ID_LOGICAL_OR);
    case Lexer::ID_LOGICAL_AND:
        return ENUM_TO_CSTR(Lexer::ID_LOGICAL_AND);
    case Lexer::ID_IS_GREATER:
        return ENUM_TO_CSTR(Lexer::ID_IS_GREATER);
    case Lexer::ID_IS_LESSER:
        return ENUM_TO_CSTR(Lexer::ID_IS_LESSER);
    case Lexer::ID_IS_EQUAL:
        return ENUM_TO_CSTR(Lexer::ID_IS_EQUAL);
    case Lexer::ID_ADDITION:
        return ENUM_TO_CSTR(Lexer::ID_ADDITION);
    case Lexer::ID_SUBTRACTION:
        return ENUM_TO_CSTR(Lexer::ID_SUBTRACTION);
    case Lexer::ID_MULTIPLICATION:
        return ENUM_TO_CSTR(Lexer::ID_MULTIPLICATION);
    case Lexer::ID_DIVISION:
        return ENUM_TO_CSTR(Lexer::ID_DIVISION);
    case Lexer::ID_SPACE:
        return ENUM_TO_CSTR(Lexer::ID_SPACE);
    case Lexer::ID_IDENTIFIER:
        return ENUM_TO_CSTR(Lexer::ID_IDENTIFIER);
    case Lexer::ID_ANY:
        return ENUM_TO_CSTR(Lexer::ID_ANY);
    }
    throw std::runtime_error("Unknown Lexer ID");
}
