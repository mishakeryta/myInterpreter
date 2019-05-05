
add_executable( LexerTests LexerTests.cpp )
target_link_libraries( LexerTests  LibLexer )

#add_executable( ExpressionGrammarTests ExpressionGrammarDemo.cpp )
#target_link_libraries( ExpressionGrammarTests LibGrammar )

#add_executable( ExpressionEvaluatorTests ExpressionEvaluatorTests.cpp )
#target_link_libraries( ExpressionEvaluatorTests LibEvaluator)

add_executable( StatementGrammarDemo StatementGrammarDemo.cpp )
target_link_libraries( StatementGrammarDemo LibGrammar  )

add_executable( StatementEvaluatorDemo StatementEvaluatorDemo.cpp )
target_link_libraries( StatementEvaluatorDemo LibEvaluator )
