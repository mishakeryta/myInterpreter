#ifndef LEXERIDGRAMMAR_HPP
#define LEXERIDGRAMMAR_HPP


#ifndef EXPRESSIONGRAMMAR_HPP
#define EXPRESSIONGRAMMAR_HPP

#include "lexer/Lexer.hpp"

#include <boost/spirit/include/qi_grammar.hpp>
#include <boost/spirit/include/qi_rule.hpp>

namespace Intr
{
    namespace  qi = boost::spirit::qi;

    using Skipper = qi::in_state_skipper<Lexer::lexer_def>;

    class LexerIdGrammar :
            public qi::grammar<Lexer::iterator_type, Skipper, std::size_t()>
    {
        using RuleType = qi::rule<Lexer::iterator_type, Skipper, std::size_t()>;

    public:
        LexerIdGrammar();

    private:

        RuleType m_lexerId;
    };
};

#endif // EXPRESSIONGRAMMARHPP

#endif // LEXERIDGRAMMAR_HPP
