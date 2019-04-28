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


    m_expression =
            m_arithmeticTerm                                     [CreateRegularNode(_val, _1)]
            >> *( (lexer.addition >> m_arithmeticTerm            [CreateBinaryNode(_val, _1, val(Lexer::ID_ADDITION))])
               |   (lexer.subtraction >> m_arithmeticTerm        [CreateBinaryNode(_val, _1, val(Lexer::ID_SUBTRACTION))])
            )
            ;

    m_arithmeticTerm =
            m_factor                                     [CreateRegularNode(_val, _1)]
            >> *(   (lexer.multiplication >> m_factor    [CreateBinaryNode(_val, _1, val(Lexer::ID_MULTIPLICATION))])
               |   (lexer.division >> m_factor           [CreateBinaryNode(_val, _1,val(Lexer::ID_DIVISION))])
            )
            ;

    m_factor =
                m_literal                                        [CreateRegularNode(_val, _1)]
            |   (lexer.parenthesisBegin >> m_expression          [CreateRegularNode(_val, _1)] >> lexer.parenthesisEnd)
            |   (lexer.subtraction >> m_factor                   [CreateNegativeNode(_val, _1)])
            |   (lexer.addition >> m_factor                      [CreateRegularNode(_val, _1)])
            ;

    m_literal = (lexer.intLiteral|lexer.boolLiteral) [CreateRegularNode(_val, _1)];
}
