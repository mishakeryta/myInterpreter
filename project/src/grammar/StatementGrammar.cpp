#include "grammar/StatementGrammar.hpp"
#include "ast/ExpressionAST.hpp"
#include "ast/StatementAST.hpp"

#include <boost/spirit/include/qi_action.hpp>
#include <boost/spirit/include/qi_skip.hpp>
#include <boost/spirit/include/qi_numeric.hpp>
#include <boost/spirit/include/qi_operator.hpp>
#include <boost/spirit/include/qi_omit.hpp>
#include <boost/phoenix/core/value.hpp>
#include <boost/phoenix/object/static_cast.hpp>

Intr::StatementGrammar::StatementGrammar(const Intr::Lexer &lexer) : StatementGrammar::base_type(m_statementList), m_expression(lexer)
{
    using qi::_val;
    using qi::_1;
    using qi::_2;
    using boost::phoenix::val;
    using boost::phoenix::static_cast_;

    m_statementList = m_statement[CreateStatementNode(_val, _1)] >> *m_statement[AppendStatementList(_val, _1)];
    m_statement = m_assignment[CreateStatementNode(_val, _1)];
    m_assignment = (lexer.identifier >> lexer.assignment >> m_expression >> lexer.statementEnd)[CreateAssignmentStatement(_val, _1, _2)];
}
