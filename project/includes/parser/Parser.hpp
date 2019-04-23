#ifndef PARSER_HPP
#define PARSER_HPP

#include "lexer/Lexer.hpp"

#include <boost/spirit/include/qi_grammar.hpp>

namespace Intr
{
    namespace  qi = boost::spirit::qi;

    class Parser :
            public qi::grammar<TokenType::iterator_type>
    {
        using RuleType = qi::rule<iterator_type>;
        public:
            Parser();

        RuleType test, start;

    };
};


#endif//PARSER_HPP
