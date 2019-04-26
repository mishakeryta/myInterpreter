file (GLOB GRAMMAR_SOURCES *.cpp helper/*.cpp)
add_library( LibGrammar STATIC ${GRAMMAR_SOURCES} )
target_link_libraries(LibGrammar LibLexer )
