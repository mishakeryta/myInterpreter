file(GLOB LEXER_SOURCES
    Lexer.cpp
    Helper.cpp )

add_library( LibLexer STATIC ${LEXER_SOURCES} )
