#include "evaluator/Printer.hpp"

#include <boost/variant/get.hpp>
Printer::Printer(std::ostream &out, Intr::VariableStack &variableStack) :
    m_expessionEvaluator(variableStack),
    m_out(out)
{}

bool Printer::print(Intr::ExpressionAST var)
{
    auto value = boost::apply_visitor(m_expessionEvaluator, var.expression());
    if(value.which() == 3 && boost::get<std::string>(value) == "\\n")
    {
        m_out << '\n';
        return true;
    }

    m_out << value;
    return true;
}
