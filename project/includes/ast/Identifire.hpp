#ifndef INCLUDESASTIDENTIFIRE_HPP
#define INCLUDESASTIDENTIFIRE_HPP
#include <string>

class Identifire
{
public:
    explicit  Identifire(const std::string &name);
    const std::string &name() const { return m_name; }
private:
    std::string m_name;
};

#endif // INCLUDESASTIDENTIFIRE_HPP
