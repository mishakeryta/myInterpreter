file( GLOB GRAMMAR_SOURCES
    ExpressionGrammar.cpp
    LiteralGrammar.cpp
    StatementGrammar.cpp )

add_library( LibGrammar STATIC ${GRAMMAR_SOURCES} )
target_link_libraries( LibGrammar LibAST )
