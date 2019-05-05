
#include "grammar/StatementGrammar.hpp"
#include "grammar/LiteralGrammar.hpp"
#include "ast/helper/ExpressionASTPrinter.hpp"
#include "ast/helper/StatementASTPrinter.hpp"
#include <boost/variant/apply_visitor.hpp>
#include "ast/StatementAST.hpp"

#include <iostream>
#include <vector>
#include <string>

using namespace Intr;

int main()
{
    std::string str = "fdg=3+1;fdg=2-3;if(2+3>2-1) \n{fgt = 2-4; while(2<1) fgt = 2-1; }";
    Intr::Lexer lexerFunctor;
    auto itr = std::begin(str);
    auto begin = lexerFunctor.begin(itr, str.end());
    auto end = lexerFunctor.end();
    Intr::StatementGrammar statementGrammar(lexerFunctor);
    std::string skip = "skip";
    StatementAST ast;
    Intr::qi::phrase_parse(begin, end, statementGrammar, Intr::qi::in_state(skip)[lexerFunctor.self], ast);
    std::cout << (begin == end);

    auto p = Helper::StatementASTPrinter(std::cout);
    boost::apply_visitor(p, ast.statement());

    return 0;
}
