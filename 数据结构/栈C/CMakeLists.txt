cmake_minimum_required(VERSION 3.21)
project(C)

set(CMAKE_CXX_STANDARD 23)

add_executable(C main.cpp symmetry.h LiStack.h Match_Brackets.h conversion.h SqStack.h)
