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

ModificationStatement::ModificationStatement(const std::string &indetifier, const ExpressionAST &value) :
    AssignmentStatement(indetifier, value)
{}

DeclarationStatement::DeclarationStatement(const std::string &indetifier, const ExpressionAST &value) :
    AssignmentStatement(indetifier, value)
{}


StatementAST &Detail::CreateModificationStatement(StatementAST &statement, const std::string &indetifier, const ExpressionAST &value)
{
    statement = StatementAST(ModificationStatement(indetifier, value));
    return statement;
}

