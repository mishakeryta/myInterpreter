#include "grammar/ExpressionAST.hpp"
#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/variant/recursive_variant.hpp>
#include <boost/variant/apply_visitor.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/phoenix_function.hpp>
#include <boost/test/utils/named_params.hpp>
#include <iostream>
#include <vector>
#include <string>

using namespace Intr;
typedef ExpressionAST expression_ast;
typedef BinaryOperation binary_op;
typedef UnaryOperation unary_op;
typedef NegateExpression negate_expr;
namespace client
{
namespace qi = boost::spirit::qi;
    namespace ascii = boost::spirit::ascii;

    boost::phoenix::function<negate_expr> neg;

struct ast_print
   {
       typedef void result_type;

       void operator()(boost::nfp::nil) const {}
       void operator()(int n) const { std::cout << n; }

       void operator()(expression_ast const& ast) const
       {
           boost::apply_visitor(*this, ast.expr);
       }

       void operator()(binary_op const& expr) const
       {
           std::cout << "op:" << expr.op << "(";
           boost::apply_visitor(*this, expr.left.expr);
           std::cout << ", ";
           boost::apply_visitor(*this, expr.right.expr);
           std::cout << ')';
       }

       void operator()(unary_op const& expr) const
       {
           std::cout << "op:" << expr.op << "(";
           boost::apply_visitor(*this, expr.subject.expr);
           std::cout << ')';
       }
   };

   ///////////////////////////////////////////////////////////////////////////
   //  Our calculator grammar
   ///////////////////////////////////////////////////////////////////////////
template <typename Iterator>
    struct calculator : qi::grammar<Iterator, expression_ast(), ascii::space_type>
    {
        calculator() : calculator::base_type(expression)
        {
            using qi::_val;
            using qi::_1;
            using qi::uint_;

            expression =
                term                            [_val = _1]
                >> *(   ('+' >> term            [_val += _1])
                    |   ('-' >> term            [_val -= _1])
                    )
                ;

            term =
                factor                          [_val = _1]
                >> *(   ('*' >> factor          [_val *= _1])
                    |   ('/' >> factor          [_val /= _1])
                    )
                ;

            factor =
                uint_                           [_val = _1]
                |   '(' >> expression           [_val = _1] >> ')'
                |   ('-' >> factor              [_val = neg(_1)])
                |   ('+' >> factor              [_val = _1])
                ;
        }

        qi::rule<Iterator, expression_ast(), ascii::space_type>
        expression, term, factor;
    };
}


///////////////////////////////////////////////////////////////////////////////
//  Main program
///////////////////////////////////////////////////////////////////////////////

int main()
{
   std::cout << "/////////////////////////////////////////////////////////\n\n";
   std::cout << "Expression parser...\n\n";
   std::cout << "/////////////////////////////////////////////////////////\n\n";
   std::cout << "Type an expression...or [q or Q] to quit\n\n";

   using boost::spirit::ascii::space;
   using client::ast_print;

   typedef std::string::const_iterator iterator_type;
   typedef client::calculator<iterator_type> calculator;

   calculator calc; // Our grammar

   std::string str;
   while (std::getline(std::cin, str))
   {
       if (str.empty() || str[0] == 'q' || str[0] == 'Q')
           break;

       std::string::const_iterator iter = str.begin();
       std::string::const_iterator end = str.end();
       expression_ast ast;
       ast_print printer;
       bool r = phrase_parse(iter, end, calc, space, ast);

       if (r && iter == end)
       {
           std::cout << "-------------------------\n";
           std::cout << "Parsing succeeded\n";
           printer(ast);
           std::cout << "\n-------------------------\n";
       }
       else
       {
           std::string rest(iter, end);
           std::cout << "-------------------------\n";
           std::cout << "Parsing failed\n";
           std::cout << "stopped at: \": " << rest << "\"\n";
           std::cout << "-------------------------\n";
       }
   }

   std::cout << "Bye... :-) \n\n";
   return 0;
}
