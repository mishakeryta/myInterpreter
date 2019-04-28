#ifndef EXPRESSIONGRAMMAR_HPP
#define EXPRESSIONGRAMMAR_HPP

#include "lexer/Lexer.hpp"
#include "ast/ExpressionAST.hpp"

#include <boost/spirit/include/qi_grammar.hpp>
#include <boost/spirit/include/qi_rule.hpp>

namespace Intr
{
    namespace  qi = boost::spirit::qi;

    using Skipper = qi::in_state_skipper<Lexer::lexer_def>;

    class ExpressionGrammar :
            public qi::grammar<Lexer::iterator_type, ExpressionAST(), Skipper>
    {
        using RuleType = qi::rule<iterator_type, ExpressionAST(), Skipper>;

    public:
        ExpressionGrammar(const Lexer& lexer);

    private:

        RuleType m_expression, m_logicalTerm ,m_arithmeticTerm, m_nontrivialTerm, m_factor, m_literal;
    };
};

#endif // EXPRESSIONGRAMMARHPP
