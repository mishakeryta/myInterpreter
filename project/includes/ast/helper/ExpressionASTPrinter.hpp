#ifndef EXPRESSIONASTPRINTER_HPP
#define EXPRESSIONASTPRINTER_HPP

#include "ast/ExpressionAST.hpp"

#include <boost/mpl/contains.hpp>
#include <boost/utility/enable_if.hpp>
#include <ostream>

namespace Intr
{
    namespace  Helper
    {
        class ExpressionASTPrinter
        {
        public:
            ExpressionASTPrinter(std::ostream& out);
            void operator()(Nil) const { }

            template<typename Lit>
            typename boost::enable_if<boost::mpl::contains< LiteralTypes, Lit >>::type
            operator()(const Lit &value) const { m_out << value; }


            void operator()(const ExpressionAST &ast) const;

            void operator()(const BinaryOperation &binary) const;

            void operator()(UnaryOperation &unary) const;
        private:
            std::ostream& m_out;
        };
    };
};
#endif //EXPRESSIONASTPRINTER_HPP
