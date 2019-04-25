#ifndef PARSER_HPP
#define PARSER_HPP

#include "lexer/Lexer.hpp"
#include "grammar/ExpressionAST.hpp"

#include <boost/spirit/include/qi_grammar.hpp>
#include <boost/spirit/include/qi_rule.hpp>

namespace Intr
{
    namespace  qi = boost::spirit::qi;

    class ExpressionGrammar :
            public qi::grammar<Lexer::iterator_type, ExpressionAST()>
    {
        using RuleType = qi::rule<iterator_type, ExpressionAST()>;
    public:

        ExpressionGrammar();


    private:

        RuleType m_expression, m_term, m_factor;
    };
};


#endif//PARSER_HPP
