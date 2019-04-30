#include "ast/ExpressionAST.hpp"
#include "evaluator/ExpressionEvaluator.hpp"

#include <boost/variant/apply_visitor.hpp>

using namespace Intr;

ExpressionEvaluator::ResultType ExpressionEvaluator::operator()(Nil) const
{
    BOOST_ASSERT_MSG(true, "ExpressionEvaluator:: Nil never suppose to heppen");
    return 0;
}

ExpressionEvaluator::ResultType ExpressionEvaluator::operator()(const Intr::ExpressionAST &ast) const
{
    return boost::apply_visitor(*this, ast.expression());
}


namespace  Detail
{
    class BinaryOperationEvaluator :
            public boost::static_visitor<ExpressionEvaluator::ResultType>
    {
        using ResultType = result_type;
    };
};

ExpressionEvaluator::ResultType ExpressionEvaluator::operator()(const Intr::BinaryOperation &expr) const
{
    ResultType leftVal = boost::apply_visitor(*this, expr.left().expression());
    ResultType rightVal = boost::apply_visitor(*this, expr.right().expression());


    return leftVal;
}

ExpressionEvaluator::ResultType ExpressionEvaluator::operator()(const Intr::UnaryOperation &unary) const
{
    if(unary.operation() != Lexer::ID_SUBTRACTION)
        throw std::logic_error("Unknown unary operation");

    return  boost::apply_visitor(*this, unary.subject().expression());
}



