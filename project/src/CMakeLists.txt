add_subdirectory( lexer )
add_subdirectory( ast )
add_subdirectory( grammar )
add_subdirectory( evaluator )

file (GLOB INTERPRETER_SOURCES
     Interpreter.cpp)

add_library( LibInterpreter STATIC ${INTERPRETER_SOURCES})
target_link_libraries(LibInterpreter LibEvaluator )
