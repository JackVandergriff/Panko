cmake_minimum_required(VERSION 3.19)
project(Panko)

SET(CLANG_COMPILE_FLAGS "-Wall -Wpedantic -Wextra")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CLANG_COMPILE_FLAGS}")

add_executable(Panko
        panko.cpp antlr4-runtime/PankoLexer.cpp antlr4-runtime/PankoParser.cpp panko_ast.h panko_interpreter.h panko_ast_builder.h panko_ast_visitor.h panko_util.h panko_scope.h panko_ast_builder.cpp panko_interpreter.cpp panko_scope.cpp panko_util.cpp)


include_directories(antlr4-runtime)
target_link_libraries(Panko antlr4-runtime)