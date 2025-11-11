cmake_minimum_required(VERSION 3.31.0)

project(Calculator LANGUAGES CXX)

set(SOURCE
    main.cpp
    token_stream.cpp
    variable.cpp
    grammar.cpp
    output.cpp
    calculator.cpp

)

set(executable_name calculator)

add_executable(${executable_name} ${SOURCE})

target_compile_features(${executable_name} PRIVATE cxx_std_17)
target_compile_options(${executable_name} PRIVATE -Wall -Wextra -pedantic)