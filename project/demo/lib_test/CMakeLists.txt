
#add_executable( LexerTests LexerTests.cpp )
#target_link_libraries( LexerTests  LibLexer )



add_executable( ParserTests ParserTests.cpp)
target_link_libraries( ParserTests LibGrammar)

add_executable( ExpressionEvaluatorTests ExpressionEvaluatorTests.cpp )
target_link_libraries( ExpressionEvaluatorTests LibEvaluator)
