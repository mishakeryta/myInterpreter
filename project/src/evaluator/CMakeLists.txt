file (GLOB EVALUATOR_SOURCES
    ExpressionEvaluator.cpp )

add_library( LibEvaluator STATIC ${EVALUATOR_SOURCES})
target_link_libraries( LibEvaluator LibGrammar)
