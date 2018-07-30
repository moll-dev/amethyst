cmake_minimum_required(VERSION 3.4 FATAL_ERROR)

project(amethyst VERSION 0.0.1 LANGUAGES CXX)

include_directories ("${PROJECT_SOURCE_DIR}/math")
add_subdirectory(math)

add_executable(amethyst_app.exe amethyst.cpp)
target_link_libraries(amethyst_app.exe math_lib)