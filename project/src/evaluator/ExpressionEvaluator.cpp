#include "ast/ExpressionAST.hpp"
#include "evaluator/ExpressionEvaluator.hpp"

#include <boost/variant/apply_visitor.hpp>
#include <boost/variant/static_visitor.hpp>

#include <cmath>

using namespace Intr;


ExpressionEvaluator::ExpressionEvaluator(VariableStack &variableStack) :
    m_variableStack(variableStack)
{}

ExpressionEvaluator::ResultType ExpressionEvaluator::operator()(Nil) const
{
    BOOST_ASSERT_MSG(true, "ExpressionEvaluator:: Nil never suppose to heppen");
    return 0;
}

ExpressionEvaluator::ResultType ExpressionEvaluator::operator()(const Intr::ExpressionAST &ast) const
{
    return boost::apply_visitor(*this, ast.expression());
}

namespace Intr
{
    namespace  Detail
    {

        class BinaryOperationEvaluator :
                public boost::static_visitor<ExpressionEvaluator::ResultType>
        {
            using NumberLiterals = boost::mpl::vector<std::int32_t, double>::type;
            static constexpr double DOUBLE_EPS = 0.000001;
        public:
            using ResultType = result_type;

            BinaryOperationEvaluator(BinaryOperation::Type operation):
                m_op(operation)
            { }

            ResultType operator()(std::int32_t literal1, std::int32_t literal2) const;
            ResultType operator()(double literal1, std::int32_t literal2) const;
            ResultType operator()(std::int32_t literal1, double literal2) const;
            ResultType operator()(double  literal1, double literal2) const;
            ResultType operator()(bool literal1, bool literal2) const;
            ResultType operator()(std::string literal1, std::string literal2) const;

            template<class Lit1, class Lit2>
            ResultType operator()(Lit1 leftVal, Lit2 rightVal) const;

        private:
            template<class Lit1, class Lit2>
            ResultType calculate(Lit1 leftLiteral, Lit2 rightLiteral) const;

            bool isZero(std::int32_t val) const;
            bool isZero(double val) const;

            bool isEqual(std::int32_t leftLiteral, std::int32_t rightLiteral) const;
            bool isEqual(double leftLiteral, std::int32_t rightLiteral) const;
            bool isEqual(std::int32_t leftLiteral, double rightLiteral) const;
            bool isEqual(double leftLiteral, double rightLiteral) const;
            bool isEqual(std::string leftLiteral, std::string rightLiteral) const;

            BinaryOperation::Type m_op;

        };

        BinaryOperationEvaluator::ResultType BinaryOperationEvaluator::operator()(std::int32_t literal1, std::int32_t literal2) const
        {
            return calculate<std::int32_t, std::int32_t>(literal1, literal2);
        }
        BinaryOperationEvaluator::ResultType BinaryOperationEvaluator::operator()(double literal1, std::int32_t literal2) const
        {
            return calculate<double, double>(literal1, literal2);
        }
        BinaryOperationEvaluator::ResultType BinaryOperationEvaluator::operator()(std::int32_t literal1, double literal2) const
        {
            return calculate<double, double>(literal1, literal2);
        }
        BinaryOperationEvaluator::ResultType BinaryOperationEvaluator::operator()(double literal1, double literal2) const
        {
            return calculate<double, double>(literal1, literal2);
        }
        BinaryOperationEvaluator::ResultType BinaryOperationEvaluator::operator()(std::string literal1, std::string literal2) const
        {
            switch (m_op)
            {
            case Lexer::ID_ADDITION:
                return literal1 + literal2;
            case Lexer::ID_IS_LESSER:
                return literal1 < literal2;
            case Lexer::ID_IS_GREATER:
                return literal1 > literal2;
            case Lexer::ID_IS_EQUAL:
                return isEqual(literal1, literal2);
            default:
                throw std::logic_error("Unknown operation for string");
            }
        }

        BinaryOperationEvaluator::ResultType BinaryOperationEvaluator::operator()(bool literal1, bool literal2) const
        {
            switch (m_op)
            {
            case Lexer::ID_LOGICAL_OR:
                return bool(literal1 || literal2);
            case Lexer::ID_LOGICAL_AND:
                return bool(literal1 && literal2);
            case Lexer::ID_IS_EQUAL:
                return literal1 == literal2;
            default:
                throw std::logic_error("Unknown logical operation");
            }
        }
        template<class Lit1, class Lit2>
        BinaryOperationEvaluator::ResultType BinaryOperationEvaluator::operator()(Lit1 leftVal, Lit2 rightVal) const
        {
            (void) leftVal;
            (void) rightVal;
            throw std::logic_error("Unknown operatio operation");
        }

        template<class Lit1, class Lit2>
        BinaryOperationEvaluator::ResultType BinaryOperationEvaluator::calculate(Lit1 leftLiteral, Lit2 rightLiteral) const
        {
            switch (m_op)
            {
            case Lexer::ID_ADDITION:
                return rightLiteral + rightLiteral;
            case Lexer::ID_SUBTRACTION:
                return leftLiteral - rightLiteral;
            case Lexer::ID_MULTIPLICATION:
                return leftLiteral * rightLiteral;
            case Lexer::ID_DIVISION:
                if(isZero(rightLiteral))
                    throw std::logic_error("Devision by zero");
                return leftLiteral / rightLiteral;
            case Lexer::ID_IS_GREATER:
                return bool(leftLiteral > rightLiteral);
            case Lexer::ID_IS_LESSER:
                return bool(leftLiteral < rightLiteral);
            case Lexer::ID_IS_EQUAL:
                return isEqual(leftLiteral, rightLiteral);
            default:
                throw std::logic_error("Unknown arithmetic operation");
            }
        }

        bool BinaryOperationEvaluator::isZero(double literal) const
        {
            return std::abs(literal) < DOUBLE_EPS;
        }

        bool BinaryOperationEvaluator::isZero(std::int32_t literal) const
        {
            return literal == 0;
        }

        bool BinaryOperationEvaluator::isEqual(std::int32_t leftLiteral,std::int32_t rightLiteral) const
        {
            return leftLiteral == rightLiteral;
        }

        bool BinaryOperationEvaluator::isEqual(double leftLiteral,std::int32_t rightLiteral) const
        {
            return isEqual(leftLiteral, static_cast<double>(rightLiteral));
        }

        bool BinaryOperationEvaluator::isEqual(std::int32_t leftLiteral, double  rightLiteral) const
        {
            return isEqual(static_cast<double>(leftLiteral), rightLiteral);
        }

        bool BinaryOperationEvaluator::isEqual(double leftLiteral, double rightLiteral) const
        {
            return std::abs(leftLiteral - rightLiteral) < DOUBLE_EPS;
        }
        bool BinaryOperationEvaluator::isEqual(std::string leftLiteral, std::string rightLiteral) const
        {
            return leftLiteral == rightLiteral;
        }
    };
};

ExpressionEvaluator::ResultType ExpressionEvaluator::operator()(const Intr::BinaryOperation &expr) const
{
    ResultType leftVal = boost::apply_visitor(*this, expr.left().expression());
    ResultType rightVal = boost::apply_visitor(*this, expr.right().expression());

    Detail::BinaryOperationEvaluator evaluator(expr.operatrion());
    return boost::apply_visitor(evaluator, leftVal, rightVal);
}

ExpressionEvaluator::ResultType ExpressionEvaluator::operator()(const Intr::UnaryOperation &unary) const
{
    if(unary.operation() != Lexer::ID_SUBTRACTION)
        throw std::logic_error("Unknown unary operation");

    return  boost::apply_visitor(*this, unary.subject().expression());
}

ExpressionEvaluator::ResultType ExpressionEvaluator::operator()(const Identifier &id)
{
    auto variable = m_variableStack.findVariable(id.name());
    if(variable)
        return *variable;
    return 0;
    throw std::logic_error("Undefined variable");
}



