cmake_minimum_required(VERSION 3.6)
project(Assist)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp rapidjson/)
add_executable(Assist ${SOURCE_FILES})