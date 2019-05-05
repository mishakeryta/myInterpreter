#include "evaluator/VariableStack.hpp"
#include <iostream>


namespace  Intr
{
    VariableStack::VariableStack() :
        m_variables(),
        m_parent()
    {}

    VariableStack::VariableStack(VariableStack &parent) :
        m_variables(),
        m_parent(parent)
    { }
    namespace Detail
    {
        class VariableModificator :
                public boost::static_visitor<bool>

        {
            public:
                using ResultType = result_type;
                template<class Lit>
                ResultType operator()(Lit &val, const Lit &newVal);
                template<class Lit1, class Lit2>
                ResultType operator()(Lit1 &val, const Lit2 &newVal);
        };

        template<class Lit>
        VariableModificator::ResultType VariableModificator::operator()(Lit &val, const Lit &newValue)
        {
            val = newValue;
            return  true;

        }

        template<class Lit1, class Lit2>
        VariableModificator::ResultType VariableModificator::operator()(Lit1 &val, const Lit2 &newValue)
        {
            (void) val;
            (void) newValue;
            std::cout << "\nFalse";

            return false;
        }
    }


    bool VariableStack::assign(const std::string &name, const Literal & value)
    {
        auto variable = findVariable(name);
        if(variable)
        {
            Detail::VariableModificator modificator;
            if(boost::apply_visitor(modificator, *variable, value))
            {
                return true;
            }
            return false;
        }
        addVariable(name, value);
        return false;
    }

    boost::optional<Literal &> VariableStack::findVariable(const std::string &name)
    {

        auto variableIterator = m_variables.find(name);
        if(variableIterator == std::end(m_variables))
        {
            std::cout << "Stic";
            return (*variableIterator).second;
        }
        std::cout << "not finded";

        if(m_parent)
            return m_parent->findVariable(name);
        return boost::optional<Literal &>();
    }

    VariableStack &VariableStack::addVariable(const std::string &name, const Literal &value)
    {
        m_variables[name] = value;
        return *this;
    }
}
