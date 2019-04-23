#ifndef PARSER_HPP
#define PARSER_HPP

#include "lexer/Lexer.hpp"
#include "grammar/ExpressionAST.hpp"

#include <boost/spirit/include/qi_grammar.hpp>
#include <boost/spirit/include/qi_rule.hpp>

namespace Intr
{
    namespace  qi = boost::spirit::qi;

    class ExpressionGrammar :
            public qi::grammar<Lexer::iterator_type, ExpressionAST()>
    {
        using RuleType = qi::rule<iterator_type, ExpressionAST()>;
    public:

        ExpressionGrammar() : ExpressionGrammar::base_type(m_expression)
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


    private:

        RuleType m_expression, m_term, m_factor;
    };
};


#endif//PARSER_HPP
