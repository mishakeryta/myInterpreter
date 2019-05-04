#ifndef STATEMENTASTPRINTER_HPP
#define STATEMENTASTPRINTER_HPP


#include "ast/StatementAST.hpp"
#include "ast/helper/ExpressionASTPrinter.hpp"
#include <ostream>
#include "ast/StatementAST.hpp"
#include "ast/helper/ExpressionASTPrinter.hpp"
namespace Intr
{
    namespace  Helper
    {
        class StatementASTPrinter :
                 public boost::static_visitor<void>
        {
        public:
            using ResultType = result_type;
            StatementASTPrinter(std::ostream& out);

            ResultType operator()(Nil) { }


            ResultType operator()(const AssignmentStatement &assign);

        private:
            std::string calculateAlign() const;

            ExpressionASTPrinter m_exrpessionPrinter;
            std::ostream& m_out;
            mutable std::size_t m_nestingCount;

        };
    };
};

#endif // STATEMENTASTPRINTER_HPP

