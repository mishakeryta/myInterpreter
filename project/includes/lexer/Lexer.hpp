#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <string>
#include <cstdint>

#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/lex_lexertl.hpp>
#include <boost/spirit/include/phoenix.hpp>
#include <boost/phoenix/object/construct.hpp>

namespace Intr
{
	using namespace boost::spirit;

	using TokenType = lex::lexertl::token<std::string::iterator>;
    using LexerType = lex::lexertl::actor_lexer<TokenType>;
    class Lexer : public lex::lexer<LexerType>
	{
	public:
		enum Id
		{
            ID_DOUBLE_NUMBER = lex::min_token_id + 1,
            ID_INT_NUMBER,

            ID_IF_STATEMENT,
            ID_WHILE_STATEMENT,

            ID_SCOPE_BEGIN,
            ID_SCOPE_END,
            ID_PARENTHESIS_BEGIN,
            ID_PARENTHESIS_END,
            ID_STATEMENT_END,

            ID_ADDITION,
            ID_SUBTRACTION,
            ID_MULTIPLICATION,
            ID_DIVISION,

            ID_IDENTIFIER,
            ID_ANY
		};

        Lexer();

        lex::token_def<double> doubleNumber;
        lex::token_def<std::int32_t> intNumber;
        lex::token_def<> ifStatement, whileStatement;
        lex::token_def<> scopeBegin, scopeEnd;
        lex::token_def<> parenthesisBegin, parenthesisEnd;
        lex::token_def<> statementEnd;
        lex::token_def<> addition, subtraction;
        lex::token_def<> division, multiplication;
        lex::token_def<std::string>  identifier;
        lex::token_def<std::string> any;
	};
};

#endif
