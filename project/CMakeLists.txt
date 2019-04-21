project( myInterpreter )
cmake_minimum_required( VERSION 3.10.2 )

set (CMAKE_CXX_STANDARD 17)

include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/includes )


set(BOOST_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../lib/boost/boost_1_70_0/")
set (Boost_USE_STATIC_RUNTIME ON)  
set(Boost_USE_STATIC_LIBS ON) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME ON) 
find_package(Boost) 

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
endif()


add_subdirectory( src )
add_subdirectory( demo )
