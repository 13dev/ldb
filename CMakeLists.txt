set (CMAKE_C_STANDARD 99)
project(ldb)
add_executable(ldb main.c compiler/parser.c compiler/parser.h)