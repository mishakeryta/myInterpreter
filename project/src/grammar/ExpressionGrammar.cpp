#include "grammar/ExpressionGrammar.hpp"
#include <boost/phoenix.hpp>
#include <boost/spirit/include/qi_action.hpp>


#include <iostream>

using namespace Intr;



ExpressionGrammar::ExpressionGrammar() : ExpressionGrammar::base_type(m_expression)
{
    using qi::_val;
    using qi::_1;


   /* auto addition = qi::token(Lexer::ID_ADDITION);
    auto subtraction = qi::token(Lexer::ID_SUBTRACTION);
    auto multiplication = qi::token(Lexer::ID_MULTIPLICATION);
    auto division = qi::token(Lexer::ID_DIVISION);
    auto parenthesisBegin = qi::token(Lexer::ID_PARENTHESIS_BEGIN);
    auto parenthesisEnd = qi::token(Lexer::ID_PARENTHESIS_END);
    auto value = qi::token(Lexer::ID_INT_NUMBER);

    m_expression =
            m_term                            [CreateRegularNode(_val, _1)]
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
