#ifndef EXPRESSIONASTPRINTER_HPP
#define EXPRESSIONASTPRINTER_HPP

#include "ast/ExpressionAST.hpp"

namespace Intr
{
    namespace  Helper
    {
        class ExpressionASTPrinter
        {
        public:
            void operator()(Nil) const { }
            void operator()(int n) const;

            void operator()(const ExpressionAST &ast) const;

            void operator()(const BinaryOperation &binary) const;

            void operator()(UnaryOperation &unary) const;
        };
    };
};
#endif //EXPRESSIONASTPRINTER_HPP
