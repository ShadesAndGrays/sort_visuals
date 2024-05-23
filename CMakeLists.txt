cmake_minimum_required(VERSION 3.14)

project(sort_visuals CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS on)

include_directories(include)

set(src
src/main.cpp
src/sorts.cpp
)

add_executable(sort_visuals ${src})

target_link_libraries(${PROJECT_NAME} fmt raylib)
