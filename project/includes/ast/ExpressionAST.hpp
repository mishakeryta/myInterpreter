#ifndef EXPRESSIONAST_HPP
#define EXPRESSIONAST_HPP

#include "lexer/Lexer.hpp"
#include "ast/Literal.hpp"
#include "ast/Identifier.hpp"

#include <boost/variant/recursive_variant.hpp>
#include <boost/variant/apply_visitor.hpp>
#include <boost/phoenix/function/adapt_function.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/back_inserter.hpp>
#include <boost/mpl/copy.hpp>

#include <memory>

namespace Intr
{
    namespace mpl = boost::mpl;

    class BinaryOperation;
    class UnaryOperation;
    class Nil { };
    class ExpressionAST
    {
        using ExpressionTypes = mpl::vector<
                Nil,
                Identifier,
                boost::recursive_wrapper<ExpressionAST>,
                boost::recursive_wrapper<BinaryOperation>,
                boost::recursive_wrapper<UnaryOperation>
            >::type;
        using LiteralTypes = Intr::LiteralTypes;
    public:
        using Type = boost::make_variant_over<mpl::copy<
                    ExpressionTypes,
                    mpl::back_inserter<LiteralTypes>
                >::type>::type;


        ExpressionAST();

        template <typename Expr>
        ExpressionAST(const Expr &expr)
          : m_expression(expr) {}

        ExpressionAST &binaryOperation(const ExpressionAST &right, Lexer::Id operation);

        const Type& expression() const { return m_expression; }

    private:
        Type m_expression;
    };

    class BinaryOperation
    {
    public:
        using Type = Lexer::Id;

        BinaryOperation(Type op, const ExpressionAST &left, const ExpressionAST &right);

        Type operatrion() const { return m_op; }
        const ExpressionAST &left() const { return m_left; }
        const ExpressionAST &right() const { return m_right; }

    private:
        Type m_op;
        ExpressionAST m_left;
        ExpressionAST m_right;
    };

    class UnaryOperation
    {
    public:
        using Type = Lexer::Id;

        UnaryOperation(Type op, const ExpressionAST& subject);

        Type operation() const { return m_op; }
        const ExpressionAST &subject() const { return m_subject; }

    private:
        Type m_op;
        ExpressionAST m_subject;
    };

    namespace Detail
    {
        template<class Expr>
        ExpressionAST &CreateRegularNode(ExpressionAST &leftExpression, const Expr &rightExpression)
        {
            return leftExpression = rightExpression;
        }
        ExpressionAST &CreateBinaryNode(ExpressionAST &leftExpression, const ExpressionAST &rightExpression, Lexer::Id operation);
        ExpressionAST &CreateNegativeNode(ExpressionAST &leftExpression, const ExpressionAST &rightExpression);
        ExpressionAST &CreateIdentifire(ExpressionAST &leftExpression, const std::string &name);
        ExpressionAST &CreatePrintSstatement(ExpressionAST &leftExpression, const ExpressionAST &rightExpression);
    };

    BOOST_PHOENIX_ADAPT_FUNCTION(ExpressionAST &, CreateRegularNode, Detail::CreateRegularNode, 2);
    BOOST_PHOENIX_ADAPT_FUNCTION(ExpressionAST &, CreateNegativeNode, Detail::CreateNegativeNode, 2);
    BOOST_PHOENIX_ADAPT_FUNCTION(ExpressionAST &, CreateBinaryNode, Detail::CreateBinaryNode, 3);
    BOOST_PHOENIX_ADAPT_FUNCTION(ExpressionAST &, CreateIdentifire, Detail::CreateIdentifire, 2);
};
#endif // EXPRESSIONAST_HPP
