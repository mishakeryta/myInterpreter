#include "lexer/Lexer.hpp"
#include "lexer/Helper.hpp"
#include <string>
#include <iostream>
#include <exception>

#define ENUM_TO_CSTR(enum_id) (#enum_id)



int main()
{
	using namespace Intr::lex;

    Intr::Lexer lexerFunctor;
    auto tokenProcessor = [] (Intr::TokenType t)
	{
        std::cout << " "  << Intr::Helper::LexerIdToString(t.id()) << " ";
		return true;
	};
    std::string str = "00 12(*)  <true > &&|| - 12 a 123 _ ad {0012}ife2112{if}12while===";

    auto begin = std::begin(str);
    tokenize(begin, std::end(str), lexerFunctor, tokenProcessor);

	std::cin.get();
}
