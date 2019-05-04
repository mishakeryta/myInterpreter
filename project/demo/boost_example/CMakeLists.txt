#set( EXTRA_LIBS ${EXTRA_LIBS} LibSquare )
#set( EXTRA_LIBS ${EXTRA_LIBS} LibExtras )
#set( EXTRA_LIBS ${EXTRA_LIBS} LibCubic )

file(GLOB STATEMENT_GRAMMAR_TEST_SOURCES StatementGrammarTest.cpp)

add_executable( StatementGrammar ${STATEMENT_GRAMMAR_TEST_SOURCES} )
