cmake_minimum_required(VERSION 3.4 FATAL_ERROR)

project(amethyst VERSION 0.0.1 LANGUAGES CXX)

#include_directories("${PROJECT_SOURCE_DIR}/mcor")
add_subdirectory(core)
add_subdirectory(amethyst)