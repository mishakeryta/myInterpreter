#include "Interpreter.hpp"

//#define LOG_ENABLE
#include "Logger.hpp"
#include "grammar/StatementGrammar.hpp"
#include "ast/helper/StatementASTPrinter.hpp"

#include <boost/spirit/include/qi_parse.hpp>

#include <fstream>
#include <streambuf>

namespace Intr
{
    Interpreter::Interpreter(std::string path,std::ostream &out):
        evaluator(out),
        m_files{path},
        m_out(out)
    {}

    int Interpreter::execute()
    {

        for(const auto& file : m_files)
        {
            std::ifstream input{file};
            if(!input)
                throw std::logic_error("Incomplete input file");

            std::string code = std::string(std::istreambuf_iterator<char>(input),
                                 std::istreambuf_iterator<char>());
            StatementAST ast;
            if(createAST(code, ast))
            {

#ifdef LOG_ENABLE
                m_out << "\nFile: " << file;
                Intr::Helper::StatementASTPrinter printer(m_out);
                boost::apply_visitor(printer, ast.statement());
#endif
                boost::apply_visitor(evaluator, ast.statement());
            }
        }
        return 0;
    }

    bool Interpreter::createAST(std::string &code, StatementAST &ast)
    {
        Lexer lexer;
        auto codeTextBegin = std::begin(code);
        auto codeTokensBegin = lexer.begin(codeTextBegin, end(code));
        auto endTokensEnd = lexer.end();
        StatementGrammar statementGrammar(lexer);
        std::string skip = "skip";
        bool result = Intr::qi::phrase_parse(codeTokensBegin , endTokensEnd , statementGrammar, Intr::qi::in_state(skip)[lexer.self], ast);

        return result && codeTokensBegin == endTokensEnd;
    }
};
