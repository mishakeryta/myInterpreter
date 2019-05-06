#include "evaluator/Printer.hpp"

Printer::Printer(std::ostream &out, Intr::VariableStack &variableStack) :
    m_expessionEvaluator(variableStack),
    m_out(out)
{}

bool Printer::print(Intr::ExpressionAST var)
{
    auto value = boost::apply_visitor(m_expessionEvaluator, var.expression());
    m_out << value;
    return true;
}
