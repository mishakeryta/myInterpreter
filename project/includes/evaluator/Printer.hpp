#ifndef INCLUDESEVALUATORPRINTER_HPP
#define INCLUDESEVALUATORPRINTER_HPP

#include "iostream"
#include "ast/ExpressionAST.hpp"
#include "ast/StatementAST.hpp"
#include "evaluator/ExpressionEvaluator.hpp"
#include "evaluator/VariableStack.hpp"

#include <boost/optional/optional.hpp>


class Printer;

class Printer
{
public:
    Printer(std::ostream &out, Intr::VariableStack &variableStack);
    bool print(Intr::ExpressionAST var);
private:
    Intr::ExpressionEvaluator m_expessionEvaluator;
    std::ostream& m_out;
};

#endif // INCLUDESEVALUATORPRINTER_HPP
