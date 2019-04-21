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
    using LexerType = lex::lexertl::actor_lexer<TokenType>;
    class Lexer : public lex::lexer<LexerType>
	{
	public:
		enum Id
		{
            ID_NUMBER = lex::min_token_id + 1,
            ID_IDENTIFIER,
            ID_ANY
		};
		Lexer()
		{
			using boost::phoenix::ref;
			using boost::phoenix::construct;
            using lex::_start;
            using lex::_end;

            number = lex::token_def<std::string>("[0-9]+", ID_NUMBER);
            identifier = lex::token_def <std::string> ("[_a-zA-Z][_a-zA-Z0-9]*", ID_IDENTIFIER);
            any = lex::token_def <std::string>(".", ID_ANY);

			auto print = std::cout << construct<std::string>(_start, _end);
            this->self = number[print] | identifier[print]| any;
		}
		lex::token_def<std::string>  number, identifier, any;
	};
};

#endif
