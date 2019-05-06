#include "ast/StatementAST.hpp"
#include "ast/helper/ExpressionASTPrinter.hpp"

#include <boost/variant/apply_visitor.hpp>

#include <iostream>

namespace  Intr
{
    StatementAST::StatementAST() :
        m_statement(Nil())
    {}


    namespace  Detail {
        class StatementASTAppender :
                public boost::static_visitor<void>
        {
        public:
            using ResultType = result_type;

            StatementASTAppender(StatementAST::Type& currentStatement, const StatementAST &newStatement) :
                m_currentStatement(currentStatement),
                m_newStatement(newStatement)
            {}

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



    StatementList::StatementList(const StatementAST &statement) :
        m_statements{statement}
    {}

    StatementList &StatementList::append(const StatementAST &statement)
    {
        m_statements.push_back(statement);
        return *this;
    }

    CondiotionStatement::CondiotionStatement(const ExpressionAST &value, const StatementAST &trueBlock) :
        m_value(value),
        m_trueBlock(trueBlock)
    {}

    IfStatement::IfStatement(const ExpressionAST &value, const StatementAST &trueBlock, const StatementAST &falseBlock) :
        CondiotionStatement (value, trueBlock),
        m_falseBlock(falseBlock)
    {}

    IfStatement &IfStatement::setFalseBlock(const StatementAST &block)
    {
        m_falseBlock = block;
        return *this;
    }


    WhileStatement::WhileStatement(const ExpressionAST &value, const StatementAST &trueBlock) :
                CondiotionStatement (value, trueBlock)
    {}

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

    PrintStatement::PrintStatement(const ExpressionAST &value) :
        m_value(value)
    {}


    StatementAST &Detail::CreateAssignmentStatement(StatementAST &statement, const std::string &indetifier, const ExpressionAST &value)
    {
        statement = StatementAST(AssignmentStatement(indetifier, value));
        return statement;
    }

    StatementAST &Detail::CreateIfStatement(StatementAST &statement, const ExpressionAST &value, const StatementAST &trueBlock, const StatementAST& falseBlock)
    {
        return statement = IfStatement(value, trueBlock, falseBlock);
    }

    StatementAST &Detail::CreateWhileStatement(StatementAST &statement, const ExpressionAST &value, const StatementAST &trueBlock)
    {
       return statement = WhileStatement(value, trueBlock);
    }
    StatementAST &Detail::CreatePrintStatement(StatementAST &statement, const ExpressionAST &value)
    {
       return statement = StatementAST(PrintStatement(value));
    }

};
