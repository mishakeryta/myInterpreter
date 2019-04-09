file (GLOB EXTRAS *.cpp)
add_library( LibExtras STATIC ${EXTRAS} )
target_link_libraries( LibParser )
