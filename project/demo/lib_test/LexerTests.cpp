#include "lexer/Lexer.hpp"
#include "lexer/helper/LexerIdGrammar.hpp"
#include "lexer/helper/LexerIdToString.hpp"
#include "grammar/ExpressionGrammar.hpp"

#include <boost/spirit/include/lex_tokenize_and_parse_attr.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/phoenix/object/static_cast.hpp>
#include <string>
#include <iostream>
#include <exception>

int main()
{
	using namespace Intr::lex;

    namespace  qi = boost::spirit::qi;
    namespace  lex = boost::spirit::lex;

    Intr::Lexer lexerFunctor;
    auto tokenProcessor = [] (auto t)
	{
        std::cout << " "  << Intr::Helper::LexerIdToString(t) << " ";
		return true;
	};
    std::string str = "00 a a \"aa\" 12(*) \"qsad12 %$3lr oasd\"  <true \"ASD  M<>/QO12847UHADSOJ \"> &&|| - 12 a 123 _ ad {0012}ife2112{if}12while===";

    auto begin = std::begin(str);
    lex::tokenize_and_phrase_parse(begin, end(str), lexerFunctor, *Intr::LexerIdGrammar()[tokenProcessor], qi::in_state("skip")[lexerFunctor.self]);

}
