#ifndef STATEMENTASTPRINTER_HPP
#define STATEMENTASTPRINTER_HPP


#include "ast/StatementAST.hpp"
#include "ast/helper/ExpressionASTPrinter.hpp"

#include <ostream>

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
            ResultType operator()(const StatementList &list);

        private:
            std::string calculateAlign() const;

            ExpressionASTPrinter m_exrpessionPrinter;
            std::ostream& m_out;
            std::size_t m_nestingCount = 0;

        };
    };
};

#endif // STATEMENTASTPRINTER_HPP

