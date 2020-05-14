cmake_minimum_required(VERSION 3.8)

project( pg )

set ( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin )

add_subdirectory( stl )

#add_library(test test.c)

add_executable( main prim.cpp )
#target_link_libraries(main test)