#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <cstdint>


#include <boost/spirit/include/lex_lexertl.hpp>
#include <boost/phoenix/function/function.hpp>

namespace Intr
{

    namespace lex = boost::spirit::lex;
    namespace qi = boost::spirit::qi;

    using TokenType = lex::lexertl::token<std::string::iterator,  boost::mpl::vector<bool, std::int32_t, double, std::string>>;
    using LexerType = lex::lexertl::actor_lexer<TokenType>;

    class Lexer :
            public lex::lexer<LexerType>
	{
	public:
		enum Id
		{
            ID_BEGIN = lex::min_token_id + 1,
            ID_STRING_LITERAL = lex::min_token_id + 1,
            ID_DOUBLE_LITERAL,
            ID_INT_LITERAL,
            ID_BOOL_LITERAL,

            ID_IF_STATEMENT,
            ID_ELSE_STATEMENT,
            ID_WHILE_STATEMENT,

            ID_SCOPE_BEGIN,
            ID_SCOPE_END,
            ID_PARENTHESIS_BEGIN,
            ID_PARENTHESIS_END,
            ID_STATEMENT_END,


            ID_ASSIGNMENT,
            ID_LOGICAL_OR,
            ID_LOGICAL_AND,
            ID_IS_GREATER,
            ID_IS_LESSER,
            ID_IS_EQUAL,

            ID_ADDITION,
            ID_SUBTRACTION,
            ID_MULTIPLICATION,
            ID_DIVISION,

            ID_WHITESPACE,

            ID_PRINT,

            ID_IDENTIFIER,
            ID_END,
            ID_ANY

		};

        Lexer();

        lex::token_def<std::string> stringLiteral;
        lex::token_def<double> doubleLiteral;
        lex::token_def<std::int32_t> intLiteral;
        lex::token_def<bool> boolLiteral;
        lex::token_def<lex::omit> ifStatement, whileStatement, elseStatement;
        lex::token_def<lex::omit> scopeBegin, scopeEnd;
        lex::token_def<lex::omit> parenthesisBegin, parenthesisEnd;
        lex::token_def<lex::omit> statementEnd;
        lex::token_def<lex::omit> assignment;
        lex::token_def<lex::omit> logicalOr, logicalAnd;
        lex::token_def<lex::omit> isGreater, isLesser, isEqual;
        lex::token_def<lex::omit> addition, subtraction;
        lex::token_def<lex::omit> division, multiplication;
        lex::token_def<lex::omit> whitespace;
        lex::token_def<lex::omit> print;
        lex::token_def<std::string> identifier;
        lex::token_def<std::string> any;
	};
};

#endif //LEXER_HPP
