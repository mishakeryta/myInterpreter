#include "lexer/Lexer.hpp"
#include <string>
#include <iostream>


int main()
{
	using namespace intr::lex;

	
    intr::Lexer lexerFunctor;
	auto tokenProcessor = [] (auto t) 
	{

		std::cout << " Match ";
		return true;
	};
	std::string str = "123 _ad 12 dde2112";

    auto begin = std::begin(str);
    tokenize(begin, std::end(str), lexerFunctor, tokenProcessor);
	std::cin.get();
}

