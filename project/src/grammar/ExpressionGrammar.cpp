#include "grammar/ExpressionGrammar.hpp"
#include <boost/phoenix.hpp>
#include <boost/spirit/include/qi_action.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>

#include <iostream>

using namespace Intr;



ExpressionGrammar::ExpressionGrammar(const Lexer& lexer) : ExpressionGrammar::base_type(m_expression)
{
    using qi::_val;
    using qi::_1;
	//FIXME: step by step uncomment and fixing of occuring issues is required 
    m_expression =
                     m_term                         [CreateRegularNode(_val, _1)]
            >> *( (lexer.addition >> m_term         [CreateAdditionNode(_val, _1)])
            |   (lexer.subtraction >> m_term        [CreateSubtractionNode(_val, _1)])
            )
            ;

            m_term =
            m_factor                                     [CreateRegularNode(_val, _1)]
            >> *(   (lexer.multiplication >> m_factor    [CreateMultiplicationNode(_val, _1)])
            |   (lexer.division >> m_factor              [CreateDivisionNode(_val, _1)])
            )
            ;

            m_factor =
            lexer.intNumber                                      [CreateRegularNode(_val, _1)]
            |   (lexer.parenthesisBegin >> m_expression          [CreateRegularNode(_val, _1)] >> lexer.parenthesisEnd)
            |   (lexer.subtraction >> m_factor                   [CreateNegativeNode(_val, _1)])
            |   (lexer.addition >> m_factor                      [CreateRegularNode(_val, _1)])
            ;
}
