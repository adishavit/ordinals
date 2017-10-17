project(ordinals)
cmake_minimum_required(VERSION 3.1)

set (CMAKE_CXX_STANDARD 11)
 
add_executable(ordinals ordinal_tests.cpp)

if(UNIX OR CMAKE_COMPILER_IS_GNUCXX)
   add_definitions("-Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic")
else(MSVC)
   add_definitions("/W4 /WX")
endif() 
