cmake_minimum_required(VERSION 3.10)
project(Heart)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/heads/master.tar.gz
)
FetchContent_MakeAvailable(raylib)

add_executable(heart heart.cpp)

target_link_libraries(heart raylib)

if (EMSCRIPTEN)
    set_target_properties(heart PROPERTIES SUFFIX ".html")
    target_link_options(heart PRIVATE
        "-sUSE_GLFW=3"
        "-sWASM=1"
        "-sALLOW_MEMORY_GROWTH=1"
        "SHELL:--preload-file ${CMAKE_CURRENT_SOURCE_DIR}/bgm.mp3@bgm.mp3"
        "SHELL:--preload-file ${CMAKE_CURRENT_SOURCE_DIR}/font.ttf@font.ttf"
        "SHELL:--shell-file ${CMAKE_CURRENT_SOURCE_DIR}/minishell.html"
    )
endif()