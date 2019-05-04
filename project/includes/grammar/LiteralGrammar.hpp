#ifndef LITERALGRAMMAR_HPP
#define LITERALGRAMMAR_HPP

//FIXME: maybe we will need this class(file) for string literal(now we don't have string literal)
#include "lexer/Lexer.hpp"

#include <boost/spirit/include/qi_grammar.hpp>
#include <boost/spirit/include/qi_rule.hpp>

#include <cstdint>

namespace Intr
{
    namespace  qi = boost::spirit::qi;

    class IntNumberGrammar :
            public qi::grammar<Lexer::iterator_type, std::int32_t()>
    {
        using RuleType = qi::rule<iterator_type, std::int32_t()>;
    public:

        IntNumberGrammar(const Lexer &lexer);

    private:

        RuleType m_literal;
    };
};


#endif // LITERALGRAMMAR_HPP
