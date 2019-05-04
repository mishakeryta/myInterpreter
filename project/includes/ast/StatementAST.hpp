#ifndef STATEMENTAST_HPP
#define STATEMENTAST_HPP

#include "ast/ExpressionAST.hpp"

#include <boost/variant/recursive_wrapper.hpp>
#include <boost/variant/variant.hpp>

#include <vector>
namespace Intr
{
          //impl
    class IfStatement{};
    class WhileStatement{};
    class StatementList{};

    class AssignmentStatement
    {
    public:
        AssignmentStatement(const std::string &idetifier, const ExpressionAST &value);
        const std::string &idetidier() const { return m_identifier; }
        const ExpressionAST &value() const { return m_value; }

    private:
        std::string m_identifier;
        ExpressionAST m_value;
    };

//    class ModificationStatement:
//            public AssignmentStatement
//    {
//    public:
//        ModificationStatement(const std::string &indetifier, const ExpressionAST &value);
//    };

//    class DeclarationStatement:
//            public AssignmentStatement
//    {
//    public:
//        DeclarationStatement(const std::string &indetifier, const ExpressionAST &value);
//    };

    class StatementAST
    {
    public:
        using Type = boost::variant<Nil,
            AssignmentStatement>;
//            boost::recursive_wrapper<IfStatement>,
//            boost::recursive_wrapper<WhileStatement>,
//            boost::recursive_wrapper<AssignmentStatement>,
//            boost::recursive_wrapper<StatementList>>;


        StatementAST();

        template <class Stmt>
        StatementAST(const Stmt &stmt) :
        m_statements(stmt){}

        const Type &statements() const { return m_statements; }

    private:
        Type m_statements;
    };


    namespace Detail
    {
    template<class State>
    StatementAST &CreateStatementNode(StatementAST &leftExpression, const State &rightExpression)
    {
        return leftExpression = rightExpression;
    }
        StatementAST &CreateAssignmentStatement(StatementAST &statement, const std::string &indetifier, const ExpressionAST &value);
    };

    BOOST_PHOENIX_ADAPT_FUNCTION(StatementAST &, CreateStatementNode, Detail::CreateStatementNode, 2);
    BOOST_PHOENIX_ADAPT_FUNCTION(StatementAST &, CreateAssignmentStatement, Detail::CreateAssignmentStatement, 3);

};


#endif // STATEMENTAST_HPP
