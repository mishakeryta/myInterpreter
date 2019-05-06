#include "grammar/StatementGrammar.hpp"
#include "evaluator/StatementEvaluator.hpp"
#include "ast/StatementAST.hpp"
#include "ast/helper/StatementASTPrinter.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <map>

#include <boost/variant/apply_visitor.hpp>
#include <boost/variant/variant.hpp>
#include <boost/variant/static_visitor.hpp>
#include <boost/optional/optional.hpp>


using Literal = boost::variant <
        int,
        bool,
        double>;


static std::map<int, Literal> literals = {{1,1},{2,"232"}, {3,true},{4, 1.2}};


boost::optional<Literal&> test()
{
    auto iter = literals.find(1);
    if(iter != literals.end())
    {
        return iter->second;
    }
    return  boost::optional<Literal&>();
}

boost::optional<Literal&> test1()
{
    return test();
}

int main()
{
/*   auto var = test1();

    if(var)
    {
        std::cout << *var;
    }*/
    std::string str = "str2 = 4; str1 = str2 ; print(str1); ";

    Intr::Lexer lexerFunctor;
    auto itr = std::begin(str);
    auto begin = lexerFunctor.begin(itr, str.end());
    auto end = lexerFunctor.end();
    Intr::StatementGrammar statementGrammar(lexerFunctor);
    std::string skip = "skip";
    Intr::StatementAST ast;
    Intr::qi::phrase_parse(begin, end, statementGrammar, Intr::qi::in_state(skip)[lexerFunctor.self], ast);
    std::cout << (begin == end);

    Intr::Helper::StatementASTPrinter printer(std::cout);
    boost::apply_visitor(printer, ast.statement());

    Intr::StatementEvaluator evaluator(std::cout);
    boost::apply_visitor(evaluator, ast.statement());

    return 0;


}
