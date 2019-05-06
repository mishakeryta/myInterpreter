#ifndef STATEMENTEVALUATOR_HPP
#define STATEMENTEVALUATOR_HPP

#include "ast/StatementAST.hpp"
#include "evaluator/ExpressionEvaluator.hpp"
#include "evaluator/VariableStack.hpp"
#include "evaluator/Printer.hpp"

#include <ostream>

namespace Intr
{
    class StatementEvaluator :
             public boost::static_visitor<int>
    {
    public:
        using ResultType = result_type;

        StatementEvaluator(std::ostream &out);
        StatementEvaluator(std::ostream &out, VariableStack& parentStack);
        ResultType operator()(Nil) { return 0; }

        ResultType operator()(const AssignmentStatement &assign);
        ResultType operator()(const StatementList &list);
        ResultType operator()(const IfStatement &statement);
        ResultType operator()(const WhileStatement &statement);
        ResultType operator()(const PrintStatement &statement);

    private:
        VariableStack m_variableStack;
        ExpressionEvaluator m_exrpessionEvaluator;
        std::ostream& m_out;
    };

};

#endif // STATEMENTEVALUATOR_HPP
