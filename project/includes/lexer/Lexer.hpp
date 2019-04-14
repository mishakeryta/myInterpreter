#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <string>

#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/lex_lexertl.hpp>
#include <boost/spirit/include/phoenix.hpp>
#include <boost/phoenix/object/construct.hpp>

namespace intr
{
	using namespace boost::spirit;
	using TokenType = lex::lexertl::token<std::string::iterator>;
	template <typename LexerType>
	class Lexer : public lex::lexer<LexerType>
	{
	public:
		enum Id
		{
			NUMBER = lex::min_token_id + 1,
			IDENTIFIER,
			ANY
		};
		Lexer()
		{
			using boost::phoenix::ref;
			using boost::phoenix::construct;
			using boost::spirit::lex::_start;
			using boost::spirit::lex::_end;

			number = lex::token_def<std::string>("[0-9]+", NUMBER);
			identifier = lex::token_def <std::string> ("[_a-zA-Z][_a-zA-Z0-9]*", IDENTIFIER);
			any = lex::token_def <std::string>(".", ANY);
			// print = [](std::string::iterator first, std::string::iterator last) { std::cout << std::string(first, last); };
			auto print = std::cout << construct<std::string>(_start, _end);
			 this->self = number[print] | identifier[print]| any;
		}
		lex::token_def<std::string>  number, identifier, any;
	};
};

#endif