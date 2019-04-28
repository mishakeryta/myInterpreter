file ( GLOB AST_SOURCES
    ExpressionAST.cpp
    Literal.cpp
    helper/ExpressionASTPrinter.cpp )

add_library( LibAST STATIC ${AST_SOURCES})
target_link_libraries( LibAST LibLexer)
