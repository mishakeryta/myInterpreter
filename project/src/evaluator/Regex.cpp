#include "evaluator/Regex.hpp"

Regex::Regex()
{

}

bool Regex::findString(std::string source, std::string regex)
{    
    std::string result;
    std::regex re(regex);
    std::smatch match;
    if (std::regex_search(source, match, re) && match.size() > 1) {
        std::cout << "Yes match";
        return true;
    } else {
        std::cout << "No match";
        return false;
    }
}


