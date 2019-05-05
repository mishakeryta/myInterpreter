#include "evaluator/StatementEvaluator.hpp"
#include "evaluator/ExpressionEvaluator.hpp"

#define LOG(val) (std::cout << val);

namespace Intr
{
    StatementEvaluator::StatementEvaluator(std::ostream &out) :
        m_out(out)
    {}

    StatementEvaluator::StatementEvaluator(std::ostream &out, VariableStack& parentStack) :
        m_variableStack(parentStack),
        m_exrpessionEvaluator(m_variableStack),
        m_out(out)
    {}



    StatementEvaluator::ResultType StatementEvaluator::operator()(const AssignmentStatement &assign)
    {
        LOG("\nAssignment");
        Literal value = boost::apply_visitor(m_exrpessionEvaluator, assign.value().expression());
        if(m_variableStack.assign(assign.identifier(), value))
        {
            return 0;
        }
        throw std::logic_error("Cannot evaluate assignment operation");
    }

    StatementEvaluator::ResultType StatementEvaluator::operator()(const StatementList &list)
    {
        const StatementList::Type &statements = list.statements();
        for(const StatementAST &ast: statements)
            boost::apply_visitor(*this, ast.statement());
        return 0;
    }
    namespace Detail
    {
        class CoditionChecker
                    : public boost::static_visitor<bool>
        {
        public:
            using ResultType = result_type;

            ResultType  operator()(bool val) const { return val;}

            template<class Lit>
            ResultType operator()(const Lit &val) const
            {
                (void) val;
                throw  std::logic_error("Condition should contain bool");
            }

        };
    }

    StatementEvaluator::ResultType StatementEvaluator::operator()(const IfStatement &statement)
    {
        Literal codiotion = boost::apply_visitor(m_exrpessionEvaluator, statement.value().expression());
        Detail::CoditionChecker checker;

        StatementEvaluator evaluator(m_out, m_variableStack);
        if(boost::apply_visitor(checker, codiotion))
            return boost::apply_visitor(*this, statement.trueBlock().statement());
        else
            return boost::apply_visitor(*this, statement.falseBlock().statement());
    }

    StatementEvaluator::ResultType StatementEvaluator::operator()(const WhileStatement &statement)
    {
        Literal codiotion = boost::apply_visitor(m_exrpessionEvaluator, statement.value().expression());
        Detail::CoditionChecker checker;
        while(boost::apply_visitor(checker, codiotion))
        {
            StatementEvaluator evaluator(m_out, m_variableStack);
            boost::apply_visitor(evaluator, statement.trueBlock().statement());
        }
        return 0;
    }
};
