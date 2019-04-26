#ifndef EXPRESSIONASTPRINTER_HPP
#define EXPRESSIONASTPRINTER_HPP

class ExpressionAST;
class Nil;
class BinaryOperation;
class UnaryOperation;

namespace Intr
{
    namespace  Helper
    {
        class ExpressionASTPrinter
        {
            typedef void result_type;
        public:
            void operator()(Nil) const { }
            void operator()(int n) const;

            void operator()(const ExpressionAST &ast) const;

            void operator()(const BinaryOperation &expr) const;

            void operator()(UnaryOperation &expr) const;
        };
    }
};
#endif //EXPRESSIONASTPRINTER_HPP
