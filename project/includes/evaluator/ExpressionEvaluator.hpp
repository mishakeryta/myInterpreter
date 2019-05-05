#ifndef EXPRESSIONASTEVALUATOR_HPP
#define EXPRESSIONASTEVALUATOR_HPP


#include "ast/ExpressionAST.hpp"
#include "ast/Identifier.hpp"
#include "evaluator/VariableStack.hpp"

#include <boost/variant/static_visitor.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/utility/compare_pointees.hpp>


namespace Intr
{
    class ExpressionEvaluator :
            public boost::static_visitor<Literal>
    {
    public:
        using ResultType = result_type;

        ExpressionEvaluator() = default;
        ExpressionEvaluator(VariableStack& variableStack);

        ResultType operator()(Nil) const;

        template<typename Lit>
        typename boost::enable_if<boost::mpl::contains< LiteralTypes, Lit >,ResultType>::type
        operator()(const Lit &value) const{ return value; }

        ResultType operator()(const ExpressionAST &ast) const;

        ResultType operator()(const BinaryOperation &binary) const;

        ResultType operator()(const UnaryOperation &unary) const;

        ResultType operator()(const Identifier &id);
    private:
        VariableStack m_variableStack;
    };
};
#endif //EXPRESSIONASTPRINTER_HPP
