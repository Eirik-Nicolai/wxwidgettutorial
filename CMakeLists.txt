cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/g++")

set(CMAKE_CXX_FLAGS "-O0")

set(CXX_STANDARD "C++17")

# add_subdirectory(src)
project(wxwidget)

set(SRC_MAIN src/main.cpp )

set(SRC ${SRC_MAIN})

message ("Adding executable...")
add_executable(prog ${SRC})

message("Linking dirs....")

target_link_libraries(
    prog
    GL
    GLU
    X11
    png
    pthread
    stdc++fs
)

find_package(wxWidgets COMPONENTS net gl core base)
if(wxWidgets_FOUND)
    include(${wxWidgets_USE_FILE})
    # and for each of your dependent executable/library targets:
    target_link_libraries(prog ${wxWidgets_LIBRARIES})
endif()


target_include_directories(prog
    PRIVATE
    "/usr/local/include"
    "${CMAKE_SOURCE_DIR}/src"
    "${CMAKE_SOURCE_DIR}/includes"
)
