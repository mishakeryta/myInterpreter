#include "ast/helper/StatementASTPrinter.hpp"
#include "ast/helper/ExpressionASTPrinter.hpp"

#include <boost/variant/apply_visitor.hpp>

#include <string>

using namespace Intr;
using namespace Helper;


StatementASTPrinter::StatementASTPrinter(std::ostream &out) :
    m_exrpessionPrinter(out),
    m_out(out)
{ }

StatementASTPrinter::ResultType StatementASTPrinter::operator()(const AssignmentStatement &assign)
{
    std::string align = '\n' + calculateAlign();
    m_out << align << "Assignment: " << assign.identifier() << " Expression: ";
    boost::apply_visitor(m_exrpessionPrinter, assign.value().expression());
}

StatementASTPrinter::ResultType StatementASTPrinter::operator()(const StatementList &list)
{
    const StatementList::Type &statements = list.statements();
    for(const StatementAST &ast: statements)
        boost::apply_visitor(*this, ast.statement());
}

StatementASTPrinter::ResultType StatementASTPrinter::operator()(const IfStatement &statement)
{
    std::string align = '\n' + calculateAlign();

    m_out << align << "If condition :";
    boost::apply_visitor(m_exrpessionPrinter, statement.value().expression());

    ++m_nestingCount;
    boost::apply_visitor(*this, statement.trueBlock().statement());

    m_out << align << "Else :";
    boost::apply_visitor(*this, statement.falseBlock().statement());
    --m_nestingCount;
}

StatementASTPrinter::ResultType StatementASTPrinter::operator()(const WhileStatement &statement)
{
    std::string align = '\n' + calculateAlign();

    m_out << align << "While condition :";
    boost::apply_visitor(m_exrpessionPrinter, statement.value().expression());

    ++m_nestingCount;
    boost::apply_visitor(*this, statement.trueBlock().statement());

    --m_nestingCount;
}

std::string StatementASTPrinter::calculateAlign() const
{
    return std::string(m_nestingCount, ' ');
}

