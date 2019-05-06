#include "grammar/StatementGrammar.hpp"
#include "ast/ExpressionAST.hpp"
#include "ast/StatementAST.hpp"

#include <boost/spirit/include/qi_action.hpp>
#include <boost/spirit/include/qi_skip.hpp>
#include <boost/spirit/include/qi_numeric.hpp>
#include <boost/spirit/include/qi_operator.hpp>
#include <boost/spirit/include/qi_omit.hpp>
#include <boost/spirit/include/qi_lexeme.hpp>
#include <boost/phoenix/core/value.hpp>
#include <boost/phoenix/object/static_cast.hpp>

Intr::StatementGrammar::StatementGrammar(const Intr::Lexer &lexer) : StatementGrammar::base_type(m_statementList), m_expression(lexer)
{
    using qi::_val;
    using qi::_1;
    using qi::_2;
    using qi::_3;
    using boost::phoenix::val;
    using boost::phoenix::static_cast_;

    m_scope = lexer.scopeBegin >> m_statementList[CreateStatementNode(_val, _1)] >> lexer.scopeEnd;
    m_statementList = m_statement[CreateStatementNode(_val, _1)] >> *m_statement[AppendStatementList(_val, _1)];

    m_statement = (m_assignment | m_ifElseStatement| m_ifStatement | m_whileStatement )[CreateStatementNode(_val, _1)];

    m_assignment = (lexer.identifier >> lexer.assignment >> m_expression >> lexer.statementEnd)[CreateAssignmentStatement(_val, _1, _2)];
    m_printStatement = (lexer.print >> lexer.parenthesisBegin >> m_expression >> lexer.parenthesisEnd >> lexer.statementEnd)[CreatePrintStatement(_val, _1)];
    m_ifStatement = (lexer.ifStatement >> lexer.parenthesisBegin >> m_expression >> lexer.parenthesisEnd >> (m_scope | m_statement))[CreateIfStatement(_val, _1, _2)];

    m_ifElseStatement = (lexer.ifStatement >> lexer.parenthesisBegin >> m_expression >> lexer.parenthesisEnd >> (m_scope | m_statement) >> m_elseBlock) [CreateIfStatement(_val, _1, _2, _3)];
    m_elseBlock = ((lexer.elseStatement >> (m_statement | m_scope))[CreateStatementNode(_val, _1)]|
                 (lexer.scopeElseStatement >> m_scope)[CreateStatementNode(_val, _1)]);

    m_whileStatement = (lexer.whileStatement >> lexer.parenthesisBegin >> m_expression >> lexer.parenthesisEnd >> (m_scope | m_statement))
            [CreateWhileStatement(_val, _1, _2)];
}
