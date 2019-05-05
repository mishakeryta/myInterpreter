#ifndef INCLUDESASTIDENTIFIER_HPP
#define INCLUDESASTIDENTIFIER_HPP
#include <string>

namespace Intr
{
    class Identifier
    {
    public:
        explicit  Identifier(const std::string &name);
        const std::string &name() const { return m_name; }
    private:
        std::string m_name;
    };
};

#endif // INCLUDESASTIDENTIFIER_HPP
