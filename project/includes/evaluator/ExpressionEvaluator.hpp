#ifndef EXPRESSIONASTEVALUATOR_HPP
#define EXPRESSIONASTEVALUATOR_HPP

#include "grammar/ExpressionAST.hpp"


namespace Intr
{
    class ExpressionEvaluator
    {
    public:
        using ResultType = int;

        ResultType operator()(Nil) const;
        ResultType operator()(int value) const;

        ResultType operator()(const ExpressionAST &ast) const;

        ResultType operator()(const BinaryOperation &binary) const;

        ResultType operator()(const UnaryOperation &unary) const;
    };
};
#endif //EXPRESSIONASTPRINTER_HPP
