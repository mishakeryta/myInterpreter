#include "lexer/helper/LexerIdGrammar.hpp"
#include "lexer/Lexer.hpp"

#include <boost/spirit/include/qi_action.hpp>
#include <boost/spirit/include/qi_operator.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/phoenix/object/static_cast.hpp>

using namespace Intr;

LexerIdGrammar::LexerIdGrammar() :
    LexerIdGrammar::base_type(m_lexerId)
{

        m_lexerId =
        (qi::tokenid(Lexer::ID_DOUBLE_LITERAL) |
        qi::tokenid(Lexer::ID_INT_LITERAL) |
        qi::tokenid(Lexer::ID_BOOL_LITERAL)|

        qi::tokenid(Lexer::ID_IF_STATEMENT) |
        qi::tokenid(Lexer::ID_WHILE_STATEMENT) |

        qi::tokenid(Lexer::ID_SCOPE_BEGIN) |
        qi::tokenid(Lexer::ID_SCOPE_END) |
        qi::tokenid(Lexer::ID_PARENTHESIS_BEGIN) |
        qi::tokenid(Lexer::ID_PARENTHESIS_END) |
        qi::tokenid(Lexer::ID_STATEMENT_END) |

        qi::tokenid(Lexer::ID_ASSIGNMENT) |
        qi::tokenid(Lexer::ID_LOGICAL_OR) |
        qi::tokenid(Lexer::ID_LOGICAL_AND) |
        qi::tokenid(Lexer::ID_IS_GREATER) |
        qi::tokenid(Lexer::ID_IS_LESSER) |
        qi::tokenid(Lexer::ID_IS_EQUAL) |

        qi::tokenid(Lexer::ID_ADDITION) |
        qi::tokenid(Lexer::ID_SUBTRACTION) |
        qi::tokenid(Lexer::ID_MULTIPLICATION) |
        qi::tokenid(Lexer::ID_DIVISION) |
        qi::tokenid(Lexer::ID_IDENTIFIER))[qi::_val = qi::_1];
}
