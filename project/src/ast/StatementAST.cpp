#include "ast/StatementAST.hpp"
#include "ast/helper/ExpressionASTPrinter.hpp"

#include <boost/variant/apply_visitor.hpp>

#include <iostream>

using namespace Intr;



StatementAST::StatementAST() :
    m_statements(Nil())
{}

AssignmentStatement::AssignmentStatement(const std::string &idetifier, const ExpressionAST &value) :
    m_identifier(idetifier), m_value(value)
{}


StatementAST &Detail::CreateAssignmentStatement(StatementAST &statement, const std::string &indetifier, const ExpressionAST &value)
{
    statement = StatementAST(AssignmentStatement(indetifier, value));
    return statement;
}

