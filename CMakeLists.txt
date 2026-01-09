cmake_minimum_required(VERSION 3.10)
project(Heart)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(raylib REQUIRED)

add_executable(heart heart.cpp)

target_link_libraries(heart raylib)
