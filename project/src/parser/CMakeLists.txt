file (GLOB EXTRAS *.cpp)
add_library( LibParser STATIC ${EXTRAS} )
target_link_libraries(LibParser LibLexer )
