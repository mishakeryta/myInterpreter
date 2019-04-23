#ifndef PARSER_HPP
#define PARSER_HPP

#include "lexer/Lexer.hpp"

#include <boost/spirit/include/qi_grammar.hpp>
#include <boost/spirit/include/qi_rule.hpp>

namespace Intr
{
    namespace  qi = boost::spirit::qi;

    class Parser :
            public qi::grammar<Lexer::iterator_type>
    {
        public:
        using RuleType = qi::rule<iterator_type>;
            Parser();

        RuleType test, start;

    };
};


#endif//PARSER_HPP
