#ifndef PARSER_HPP
#define PARSER_HPP

#include "lexer/Lexer.hpp"
#include "ast/ExpressionAST.hpp"

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
        ExpressionGrammar(const Lexer& lexer);


    private:

        RuleType m_expression, logicalTerm ,m_arithmeticTerm, m_factor, m_literal;
    };
};


#endif//PARSER_HPP
