#include "grammar/StatementGrammar.hpp"
#include "evaluator/StatementEvaluator.hpp"

#include <iostream>
#include <vector>
#include <string>

using namespace Intr;

int main()
{

    std::string str = "fdg=3+1;fdg=true;if(2+3>2-1) \n{fgt = 2.2-4; while(2<1) fgt = 2-1; }";
    Intr::Lexer lexerFunctor;
    auto itr = std::begin(str);
    auto begin = lexerFunctor.begin(itr, str.end());
    auto end = lexerFunctor.end();
    Intr::StatementGrammar statementGrammar(lexerFunctor);
    std::string skip = "skip";
    StatementAST ast;
    Intr::qi::phrase_parse(begin, end, statementGrammar, Intr::qi::in_state(skip)[lexerFunctor.self], ast);
    std::cout << (begin == end);

    StatementEvaluator evaluator(std::cout);
    boost::apply_visitor(evaluator, ast.statement());

    return 0;

}
