#include "grammar/ExpressionGrammar.hpp"
#include <boost/phoenix.hpp>
#include <boost/spirit/include/qi_action.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/phoenix/core/value.hpp>

#include <iostream>

using namespace Intr;



ExpressionGrammar::ExpressionGrammar(const Lexer& lexer) : ExpressionGrammar::base_type(m_expression)
{
    using qi::_val;
    using qi::_1;
    using boost::phoenix::val;


    m_expression = m_logicalTerm                                 [CreateRegularNode(_val, _1)] >>
                *((lexer.logicalOr >>  m_logicalTerm             [CreateBinaryNode(_val, _1, val(Lexer::ID_LOGICAL_OR))]) |
                  (lexer.logicalAnd >> m_logicalTerm             [CreateBinaryNode(_val, _1, val(Lexer::ID_LOGICAL_AND))])
            );

    m_logicalTerm = m_arithmeticTerm                                 [CreateRegularNode(_val, _1)] >>
                *((lexer.isGreater >>  m_arithmeticTerm            [CreateBinaryNode(_val, _1, val(Lexer::ID_IS_GREATER))]) |
                  (lexer.isLesser >>  m_arithmeticTerm             [CreateBinaryNode(_val, _1, val(Lexer::ID_IS_LESSER))]) |
                  (lexer.isEqual >>  m_arithmeticTerm              [CreateBinaryNode(_val, _1, val(Lexer::ID_IS_EQUAL))])
            );

    m_arithmeticTerm = m_nontrivialTerm                                     [CreateRegularNode(_val, _1)]
            >> *( (lexer.addition >> m_nontrivialTerm            [CreateBinaryNode(_val, _1, val(Lexer::ID_ADDITION))])
               |   (lexer.subtraction >> m_nontrivialTerm        [CreateBinaryNode(_val, _1, val(Lexer::ID_SUBTRACTION))])
            );


    m_nontrivialTerm  =         m_factor                                     [CreateRegularNode(_val, _1)] >>
            *((lexer.multiplication >> m_factor    [CreateBinaryNode(_val, _1, val(Lexer::ID_MULTIPLICATION))]) |
            (lexer.division >> m_factor           [CreateBinaryNode(_val, _1, val(Lexer::ID_DIVISION))])
            );

    m_factor =
                m_literal                                        [CreateRegularNode(_val, _1)]
            |   (lexer.parenthesisBegin >> m_expression          [CreateRegularNode(_val, _1)] >> lexer.parenthesisEnd)
            |   (lexer.subtraction >> m_factor                   [CreateNegativeNode(_val, _1)])
            |   (lexer.addition >> m_factor                      [CreateRegularNode(_val, _1)])
            ;

    m_literal = (lexer.intLiteral|lexer.boolLiteral) [CreateRegularNode(_val, _1)];
}
