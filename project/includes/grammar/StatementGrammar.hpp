#ifndef INCLUDESGRAMMARSTATEMENTSGRAMMAR_HPP
#define INCLUDESGRAMMARSTATEMENTSGRAMMAR_HPP

#include "grammar/ExpressionGrammar.hpp"

namespace Intr
{

    class StatementGrammar :
            public qi::grammar<Lexer::iterator_type, Skipper>
    {
        template<class T = qi::unused_type>
        using RuleType = qi::rule<iterator_type, Skipper, T>;
    public:
        StatementGrammar(const Lexer& lexer);
    private:

        RuleType<> m_statement;
        RuleType<ExpressionAST()> m_expression;
    };

};

#endif // INCLUDESGRAMMARSTATEMENTSGRAMMAR_HPP
