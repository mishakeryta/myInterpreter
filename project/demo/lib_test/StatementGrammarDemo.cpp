#include "lexer/Lexer.hpp"
#include "lexer/Helper.hpp"
#include "grammar/StatementGrammar.hpp"
#include "grammar/LiteralGrammar.hpp"
#include "ast/helper/ExpressionASTPrinter.hpp"


#include <iostream>
#include <vector>
#include <string>

using namespace Intr;

int main()
{
    std::string str = "3+1;2+1";
    Intr::Lexer lexerFunctor;
    std::cout<<"La1";
    auto itr = std::begin(str);
    auto begin = lexerFunctor.begin(itr, str.end());
    auto end = lexerFunctor.end();
    Intr::StatementGrammar statementGrammar(lexerFunctor);
    std::string skip = "skip";
    std::cout << "Lalal";
    Intr::qi::phrase_parse(begin, end, statementGrammar, Intr::qi::in_state(skip)[lexerFunctor.self]);
    std::cout << (begin == end);

    return 0;
}
