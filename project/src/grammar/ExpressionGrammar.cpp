#include "grammar/ExpressionGrammar.hpp"
#include <boost/phoenix.hpp>
#include <boost/spirit/include/qi_action.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>

#include <iostream>

using namespace Intr;



ExpressionGrammar::ExpressionGrammar(const Lexer& lexer) : ExpressionGrammar::base_type(m_expression)
{
	//FIXME: step by step uncomment and fixing of occuring issues is required 
    m_expression =  lexer.intNumber[CreateRegularNode(qi::_val, qi::_1)];
   /*         m_term                            [CreateRegularNode(_val, _1)]
            >> *(   (addition >> m_term       [CreateAdditionNode(_val, _1)])
            |   (subtraction >> m_term        [CreateSubtractionNode(_val, _1)])
            )
            ;

            m_term =
            m_factor                               [CreateRegularNode(_val, _1)]
            >> *(   (multiplication >> m_factor    [CreateMultiplicationNode(_val, _1)])
            |   (division >> m_factor              [CreateDivisionNode(_val, _1)])
            )
            ;

            m_factor =
            value                                          [CreateRegularNode(_val, _1)]
            |   parenthesisBegin >> m_expression           [CreateRegularNode(_val, _1)] >> parenthesisEnd
            |   (subtraction >> m_factor                   [CreateRegularNode(_val ,_1)])
            |   (addition >> m_factor                      [CreateRegularNode(_val ,_1)])
            ;*/
}
