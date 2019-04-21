#include "lexer/Lexer.hpp"
#include <string>
#include <iostream>

#define ENUM_TO_CSTR(enum_id) (#enum_id)


std::string IdToStr(Intr::Lexer::id_type id)
{
    using Lexer = Intr::Lexer;
    switch(id){
    case Lexer::ID_IDENTIFIER:
        return ENUM_TO_CSTR(Lexer::ID_IDENTIFIER);
    case Lexer::ID_INT_NUMBER:
        return ENUM_TO_CSTR(Lexer::ID_INT_NUMBER);
    case Lexer::ID_DOUBLE_NUMBER:
        return ENUM_TO_CSTR(Lexer::ID_DOUBLE_NUMBER);
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
    case Lexer::ID_ANY:
        return ENUM_TO_CSTR(Lexer::ID_ANY);

    }
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
    std::string str = "-123_ad{12}ife2112{if}while";

    auto begin = std::begin(str);
    tokenize(begin, std::end(str), lexerFunctor, tokenProcessor);
	std::cin.get();
}

