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
    m_out << align << "Declaration of: " << assign.identidier() << " Expression: ";
    boost::apply_visitor(m_exrpessionPrinter, assign.value().expression());
}

StatementASTPrinter::ResultType StatementASTPrinter::operator()(const StatementList &list)
{
    const StatementList::Type &statements = list.statements();
    for(const StatementAST &ast: statements)
        boost::apply_visitor(*this, ast.statement());
}


std::string StatementASTPrinter::calculateAlign() const
{
    return std::string(m_nestingCount, ' ');
}

