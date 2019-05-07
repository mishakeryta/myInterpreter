#ifndef INCLUDESINTERPRETER_HPP
#define INCLUDESINTERPRETER_HPP

#include "evaluator/StatementEvaluator.hpp"

#include <string>
#include <vector>
#include <ostream>

namespace Intr
{


class Interpreter
{
    public:
        Interpreter(std::string path,std::ostream &out);
        int execute();
    private:
        bool createAST(std::string& code, StatementAST& ast);
        StatementEvaluator evaluator;
        std::vector<std::string> m_files;
        std::ostream& m_out;

    };
};

#endif // INCLUDESINTERPRETER_HPP
