file (GLOB EXTRAS *.c)
add_library( LibExtras STATIC ${EXTRAS} )
target_link_libraries( LibExtras LibSquare LibCubic )
