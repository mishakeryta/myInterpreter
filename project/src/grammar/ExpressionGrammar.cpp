#include "grammar/ExpressionGrammar.hpp"
#include <boost/phoenix.hpp>
#include <boost/spirit/include/qi_action.hpp>


#include <iostream>

using namespace Intr;


ExpressionGrammar::ExpressionGrammar() : ExpressionGrammar::base_type(m_expression)
{
    using qi::_val;
    using qi::_1;


    RuleType addition = qi::token(Lexer::ID_ADDITION),
            subtraction = qi::token(Lexer::ID_SUBTRACTION),
            multiplication = qi::token(Lexer::ID_MULTIPLICATION),
            division = qi::token(Lexer::ID_DIVISION),
            parenthesisBegin = qi::token(Lexer::ID_PARENTHESIS_BEGIN),
            parenthesisEnd = qi::token(Lexer::ID_PARENTHESIS_END),
            value = qi::token(Lexer::ID_INT_NUMBER);

    m_expression =
            m_term                            [_val = _1]
            >> *(   (addition >> m_term       [_val += _1])
            |   (subtraction >> m_term    [_val -= _1])
            )
            ;

            m_term =
            m_factor                          [_val = _1]
            >> *(   ('*' >> m_factor          [_val *= _1])
            |   ('/' >> m_factor          [_val /= _1])
            )
            ;

            m_factor =
            value                                         [_val = _1]
            |   parenthesisBegin >> m_expression           [_val = _1] >> parenthesisEnd
            |   (subtraction >> m_factor                   [_val = _1])
            |   (addition >> m_factor                      [_val = _1])
            ;
}
