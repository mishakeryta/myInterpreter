#ifndef EXPRESSIONASTPRINTER_HPP
#define EXPRESSIONASTPRINTER_HPP

#include "ast/ExpressionAST.hpp"

#include <boost/mpl/contains.hpp>
#include <boost/utility/enable_if.hpp>

namespace Intr
{
    namespace  Helper
    {
        class ExpressionASTPrinter
        {
        public:
            void operator()(Nil) const { }

            template<typename Lit>
            typename boost::enable_if<boost::mpl::contains< LiteralTypes, Lit >>::type
            operator()(const Lit &value) const { std::cout << value; }


            void operator()(const ExpressionAST &ast) const;

            void operator()(const BinaryOperation &binary) const;

            void operator()(UnaryOperation &unary) const;
        };
    };
};
#endif //EXPRESSIONASTPRINTER_HPP
