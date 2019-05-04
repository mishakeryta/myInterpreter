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

    class StatementAST
    {
    public:
        using Type = boost::variant<Nil,
                AssignmentStatement,
                boost::recursive_wrapper<StatementList>>;
//            boost::recursive_wrapper<IfStatement>,
//            boost::recursive_wrapper<WhileStatement>,
//            boost::recursive_wrapper<AssignmentStatement>,


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


    namespace Detail
    {
        template<class Statement>
        StatementAST &CreateStatementNode(StatementAST &leftStatement, const Statement &rightStatement)
        {
            return leftStatement = rightStatement;
        }
        StatementAST &AppendStatementList(StatementAST& statementList, const StatementAST &newStatement);
        StatementAST &CreateAssignmentStatement(StatementAST &statement, const std::string &indetifier, const ExpressionAST &value);
    };

    BOOST_PHOENIX_ADAPT_FUNCTION(StatementAST &, AppendStatementList, Detail::AppendStatementList, 2);
    BOOST_PHOENIX_ADAPT_FUNCTION(StatementAST &, CreateStatementNode, Detail::CreateStatementNode, 2);
    BOOST_PHOENIX_ADAPT_FUNCTION(StatementAST &, CreateAssignmentStatement, Detail::CreateAssignmentStatement, 3);

};


#endif // STATEMENTAST_HPP
