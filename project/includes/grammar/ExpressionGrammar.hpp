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
	//change now instead of tonen(ID...) we will use lexer.space(any lexer property)
        ExpressionGrammar(const Lexer& lexer);


    private:

        RuleType m_expression, m_term, m_factor, m_literal;
    };
};


#endif//PARSER_HPP
