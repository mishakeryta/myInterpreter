#ifndef VARIABLESTACK_HPP
#define VARIABLESTACK_HPP

#include <boost/optional/optional.hpp>
#include "ast/Literal.hpp"

#include <map>
#include <string>

namespace Intr
{
    class VariableStack;

    class VariableStack
    {
        using Container = std::map<std::string, Literal>;
    public:

        VariableStack();
        VariableStack(VariableStack& parent);

        bool assign(const std::string &name, const Literal & value);

        boost::optional<Literal&> findVariable(const std::string &name);

    private:
        VariableStack& addVariable(const std::string& name, const Literal &value);

        Container m_variables;
        boost::optional<VariableStack &> m_parent;

    };
}

#endif // VARIABLESTACK_HPP
