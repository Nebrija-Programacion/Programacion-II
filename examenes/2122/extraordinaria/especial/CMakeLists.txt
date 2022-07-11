cmake_minimum_required(VERSION 3.5)

project(especial LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(especial main.cpp libro.cpp editorial.cpp autor.cpp)
