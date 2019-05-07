#ifndef INCLUDESEVALUATORREGEX_HPP
#define INCLUDESEVALUATORREGEX_HPP

#include <iostream>
#include <string>
#include <regex>

class Regex
{
public:
    Regex(std::string str1, std::string str2);
    bool operator()();
private:
    std::string m_str1;
    std::string m_str2;
};

#endif // INCLUDESEVALUATORREGEX_HPP
