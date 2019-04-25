#include "grammar/LiteralGrammar.hpp"

#include <boost/spirit/include/qi_what.hpp>
#include <boost/spirit/include/qi_int.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/phoenix/function/adapt_function.hpp>
#include <boost/phoenix/object/construct.hpp>
#include <boost/spirit/include/qi_int.hpp>
#include <boost/spirit/include/qi_action.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>

#include <string>

using namespace Intr;


namespace  Detail {
    template<class Str>
    int ToIntImpl(const Str& src)
    {
        return boost::lexical_cast<int>(src);
    }
    BOOST_PHOENIX_ADAPT_FUNCTION(int, ToInt, ToIntImpl, 1);
}


IntNumberGrammar::IntNumberGrammar(const Lexer &lexer) : IntNumberGrammar::base_type(m_literal)
{
   using boost::phoenix::construct;
   m_literal = lexer.intNumber[qi::_val = qi::_1];
}
