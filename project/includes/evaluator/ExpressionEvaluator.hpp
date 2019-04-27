#ifndef EXPRESSIONASTEVALUATOR_HPP
#define EXPRESSIONASTEVALUATOR_HPP


#include "ast/ExpressionAST.hpp"

#include <boost/variant/static_visitor.hpp>

namespace Intr
{
    class ExpressionEvaluator :
            boost::static_visitor<int>
    {
    public:
        using ResultType = result_type;

        ResultType operator()(Nil) const;
        ResultType operator()(int value) const;

        ResultType operator()(const ExpressionAST &ast) const;

        ResultType operator()(const BinaryOperation &binary) const;

        ResultType operator()(const UnaryOperation &unary) const;
    };
};
#endif //EXPRESSIONASTPRINTER_HPP
