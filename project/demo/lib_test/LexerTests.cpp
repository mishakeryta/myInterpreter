#include "lexer/Lexer.hpp"
#include <string>
#include <iostream>
#include <exception>

#define ENUM_TO_CSTR(enum_id) (#enum_id)


std::string IdToStr(Intr::Lexer::id_type id)
{
    using Lexer = Intr::Lexer;
    switch(id) {
    case Lexer::ID_DOUBLE_NUMBER:
        return ENUM_TO_CSTR(Lexer::ID_DOUBLE_NUMBER);
    case Lexer::ID_INT_NUMBER:
        return ENUM_TO_CSTR(Lexer::ID_INT_NUMBER);
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
    case Lexer::ID_EQUALITY:
        return ENUM_TO_CSTR(Lexer::ID_EQUALITY);
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

int main()
{
	using namespace Intr::lex;

    Intr::Lexer lexerFunctor;
    auto tokenProcessor = [] (Intr::TokenType t)
	{
        std::cout << " "  << IdToStr(t.id()) << " ";

		return true;
	};
    std::string str = "  00 1.2   - 12 a 123 _ ad {0012}ife2112{if}12while===";

    auto begin = std::begin(str);
    tokenize(begin, std::end(str), lexerFunctor, tokenProcessor);
	std::cin.get();
}
