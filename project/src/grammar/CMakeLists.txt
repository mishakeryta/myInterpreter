file (GLOB GRAMMAR_SOURCES
    ExpressionAST.cpp
    ExpressionGrammar.cpp
    LiteralGrammar.cpp
    StatementsGrammar.cpp
    helper/ExpressionASTPrinter.cpp)

add_library( LibGrammar STATIC ${GRAMMAR_SOURCES} )
target_link_libraries(LibGrammar LibLexer )
