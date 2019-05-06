#ifndef STATEMENTAST_HPP
#define STATEMENTAST_HPP

#include "ast/ExpressionAST.hpp"

#include <boost/variant/recursive_wrapper.hpp>
#include <boost/variant/variant.hpp>

#include <vector>
namespace Intr
{
    class IfStatement;
    class WhileStatement;
    class StatementList;


    class AssignmentStatement
    {
    public:
        AssignmentStatement(const std::string &idetifier, const ExpressionAST &value);
        const std::string &identifier() const { return m_identifier; }
        const ExpressionAST &value() const { return m_value; }

    private:
        std::string m_identifier;
        ExpressionAST m_value;
    };

    class PrintStatement
    {
    public:
        PrintStatement(const ExpressionAST &value);
        const ExpressionAST &value() const { return m_value; }
    private:
        ExpressionAST m_value;
    };

    class StatementAST
    {
    public:
        using Type = boost::variant<Nil,
                AssignmentStatement,
                PrintStatement,
                boost::recursive_wrapper<StatementList>,
                boost::recursive_wrapper<IfStatement>,
                boost::recursive_wrapper<WhileStatement>>;



        StatementAST();

        template <class Stmt>
        StatementAST(const Stmt &stmt) :
        m_statement(stmt){}

        StatementAST &append(const StatementAST& statement);

        const Type &statement() const { return m_statement; }

    private:
        Type m_statement;
    };

    class StatementList
    {
    public:
        using Type = std::vector<StatementAST>;

        StatementList() = default;
        StatementList(const StatementAST& statement);

        const Type& statements() const { return m_statements; }

        StatementList& append(const StatementAST &newStatement);

    private:
        Type m_statements;
    };

    class CondiotionStatement
    {
    public:
        const ExpressionAST &value() const { return m_value; }
        const StatementAST & trueBlock() const  { return m_trueBlock; }
    protected:
        CondiotionStatement(const ExpressionAST& value, const StatementAST& trueBlock);
    private:
        ExpressionAST m_value;
        StatementAST m_trueBlock;
    };

    class IfStatement :
            public CondiotionStatement
    {
    public:
        IfStatement(const ExpressionAST& value, const StatementAST& trueBlock, const StatementAST& falseBlock = StatementAST());
        const StatementAST & falseBlock() const { return m_falseBlock; }
    private:
        StatementAST m_falseBlock;
    };

    class WhileStatement :
        public CondiotionStatement
    {
    public:
        WhileStatement(const ExpressionAST& value, const StatementAST& trueBlock);
    };


    namespace Detail
    {
        template<class Statement>
        StatementAST &CreateStatementNode(StatementAST &leftStatement, const Statement &rightStatement)
        {
            return leftStatement = rightStatement;
        }
        StatementAST &CreateAssignmentStatement(StatementAST &statement, const std::string &indetifier, const ExpressionAST &value);
        StatementAST &AppendStatementList(StatementAST &statementList, const StatementAST &newStatement);
        StatementAST &CreateIfStatement(StatementAST &statement, const ExpressionAST &value, const StatementAST& trueBlock, const StatementAST& falseBlock = StatementAST());
        StatementAST &CreateWhileStatement(StatementAST &statement, const ExpressionAST &value, const StatementAST& trueBlock);
        StatementAST &CreatePrintStatement(StatementAST &statement, const ExpressionAST &value);
    };


    BOOST_PHOENIX_ADAPT_FUNCTION(StatementAST &, CreateStatementNode, Detail::CreateStatementNode, 2);
    BOOST_PHOENIX_ADAPT_FUNCTION(StatementAST &, CreateAssignmentStatement, Detail::CreateAssignmentStatement, 3);
    BOOST_PHOENIX_ADAPT_FUNCTION(StatementAST &, AppendStatementList, Detail::AppendStatementList, 2);
    BOOST_PHOENIX_ADAPT_FUNCTION(StatementAST &, CreateIfStatement, Detail::CreateIfStatement, 3);
    BOOST_PHOENIX_ADAPT_FUNCTION(StatementAST &, CreateIfStatement, Detail::CreateIfStatement, 4);
    BOOST_PHOENIX_ADAPT_FUNCTION(StatementAST &, CreateWhileStatement, Detail::CreateWhileStatement, 3);
    BOOST_PHOENIX_ADAPT_FUNCTION(StatementAST &, CreatePrintStatement, Detail::CreatePrintStatement, 2);
};


#endif // STATEMENTAST_HPP
