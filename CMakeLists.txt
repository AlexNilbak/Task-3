cmake_minimum_required(VERSION 3.1)

project(Parser)

include_directories(${PROJECT_SOURCE_DIR})

set (Parser_SRC  main.cpp Class.cpp Parser.cpp Autotest.cpp)
set (Parser_HDR  Class.h Parser.h Autotest.h)

add_executable (${PROJECT_NAME} ${Parser_SRC} ${Parser_HDR})