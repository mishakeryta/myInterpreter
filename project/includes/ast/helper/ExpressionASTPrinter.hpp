#ifndef EXPRESSIONASTPRINTER_HPP
#define EXPRESSIONASTPRINTER_HPP

#include "ast/ExpressionAST.hpp"

#include <boost/mpl/vector.hpp>
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

            template<typename T>
            typename boost::enable_if<boost::mpl::contains< LiteralTypes, T >>::type
            operator()(const T &n) const { std::cout << n; }


            void operator()(const ExpressionAST &ast) const;

            void operator()(const BinaryOperation &binary) const;

            void operator()(UnaryOperation &unary) const;
        };
    };
};
#endif //EXPRESSIONASTPRINTER_HPP
