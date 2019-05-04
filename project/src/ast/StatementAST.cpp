#include "ast/StatementAST.hpp"
#include "ast/helper/ExpressionASTPrinter.hpp"

#include <boost/variant/apply_visitor.hpp>

#include <iostream>

using namespace Intr;



StatementAST::StatementAST() :
    m_statement(Nil())
{}

namespace  Intr {
    namespace  Detail {
        class StatementASTAppender :
                public boost::static_visitor<void>

        {
        public:
            using ResultType = result_type;

            StatementASTAppender(StatementAST::Type& currentStatement, const StatementAST &newStatement) :
                m_currentStatement(currentStatement),
                m_newStatement(newStatement)
            { }

            ResultType operator()(StatementList &list);

            template<class Stmt>
            ResultType operator()(Stmt& first);

        private:
            StatementAST::Type& m_currentStatement;
            const StatementAST& m_newStatement;

        };

        template<class Stmt>
        StatementASTAppender::ResultType StatementASTAppender::operator()(Stmt &first)
        {
            StatementList list = StatementAST(first);
            list.append(m_newStatement);
            m_currentStatement = list;
        }

        StatementASTAppender::ResultType StatementASTAppender::operator()(StatementList &list)
        {
            list.append(m_newStatement);
        }
    };
};

StatementAST &Intr::Detail::AppendStatementList(StatementAST &statementList, const StatementAST &newStatement)
{
    return statementList.append(newStatement);
}

StatementAST &StatementAST::append(const StatementAST &newStatement)
{
    Detail::StatementASTAppender appender(m_statement, newStatement);
    boost::apply_visitor(appender, m_statement);
    return *this;
}

AssignmentStatement::AssignmentStatement(const std::string &idetifier, const ExpressionAST &value) :
    m_identifier(idetifier), m_value(value)
{}


StatementAST &Detail::CreateAssignmentStatement(StatementAST &statement, const std::string &indetifier, const ExpressionAST &value)
{
    statement = StatementAST(AssignmentStatement(indetifier, value));
    return statement;
}


StatementList::StatementList(const StatementAST &statement) :
    m_statements{statement}
{}

StatementList &StatementList::append(const StatementAST &statement)
{
    m_statements.push_back(statement);
    return *this;
}
