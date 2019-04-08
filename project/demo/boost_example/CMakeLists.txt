project( CALC )
cmake_minimum_required( VERSION 3.8 )

set( EXTRA_LIBS ${EXTRA_LIBS} LibSquare )
set( EXTRA_LIBS ${EXTRA_LIBS} LibExtras )
set( EXTRA_LIBS ${EXTRA_LIBS} LibCubic )

add_executable( Calc calc.cpp )
target_link_libraries( Calc  ${EXTRA_LIBS} )
