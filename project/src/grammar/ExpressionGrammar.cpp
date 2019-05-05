#include "grammar/ExpressionGrammar.hpp"

#include <boost/spirit/include/qi_action.hpp>
#include <boost/spirit/include/qi_skip.hpp>
#include <boost/spirit/include/qi_numeric.hpp>
#include <boost/spirit/include/qi_operator.hpp>
#include <boost/phoenix/core/value.hpp>
#include <boost/phoenix/object/static_cast.hpp>

using namespace Intr;



ExpressionGrammar::ExpressionGrammar(const Lexer& lexer) : ExpressionGrammar::base_type(m_expression)
{
    using qi::_val;
    using qi::_1;
    using boost::phoenix::val;
    using boost::phoenix::static_cast_;


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
                m_identifire                                     [CreateRegularNode(_val, _1)]
            |   m_literal                                        [CreateRegularNode(_val, _1)]
            |   (lexer.parenthesisBegin >> m_expression          [CreateRegularNode(_val, _1)] >> lexer.parenthesisEnd)
            |   (lexer.subtraction >> m_factor                   [CreateNegativeNode(_val, _1)])
            |   (lexer.addition >> m_factor                      [CreateRegularNode(_val, _1)])
            ;

    m_literal = (lexer.intLiteral|lexer.doubleLiteral|lexer.stringLiteral) [CreateRegularNode(_val, _1)]|
                lexer.boolLiteral[CreateRegularNode(_val, static_cast_<bool>(_1))];
    m_identifire = lexer.identifier[CreateIdentifire(_val, _1)];
}
