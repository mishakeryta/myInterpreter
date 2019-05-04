#include "ast/helper/StatementASTPrinter.hpp"
#include "ast/helper/ExpressionASTPrinter.hpp"

#include <boost/variant/apply_visitor.hpp>

#include <string>

using namespace Intr;
using namespace Helper;

Helper::StatementASTPrinter::StatementASTPrinter(std::ostream &out) :
    m_exrpessionPrinter(out),
    m_out(out)
{ }

Helper::StatementASTPrinter::ResultType  Intr::Helper::StatementASTPrinter::operator()(const AssignmentStatement &assign)
{
    std::string align = '\n' + calculateAlign();
    m_out << align << "Declaration of: " << assign.idetidier() << " Expression: ";
    boost::apply_visitor(m_exrpessionPrinter, assign.value().expression());
}


std::string Helper::StatementASTPrinter::calculateAlign() const
{
    return std::string(m_nestingCount, ' ');
}

