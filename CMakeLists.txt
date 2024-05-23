cmake_minimum_required(VERSION 3.14)

project(sort_visuals CXX)

set(src
src/main.cpp
)

add_executable(sort_visuals ${src})

target_link_libraries(${PROJECT_NAME} fmt raylib)
