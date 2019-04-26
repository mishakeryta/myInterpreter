#ifndef HELPER_HPP
#define HELPER_HPP

#include "lexer/Lexer.hpp"
#include <string>
#include <iostream>
#include <exception>


namespace Intr
{
    namespace  Helper
    {
        std::string LexerIdToString(Intr::Lexer::id_type id);
    }
}
#endif // HELPER_HPP
