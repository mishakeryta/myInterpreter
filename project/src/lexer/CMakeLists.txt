file(GLOB LEXER_SOURCES
    Lexer.cpp
    helper/LexerIdToString.cpp
    helper/LexerIdGrammar.cpp)

add_library( LibLexer STATIC ${LEXER_SOURCES} )
