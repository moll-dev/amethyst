add_library(math_lib source/mathlib.cpp)
target_include_directories(math_lib
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_options(math_lib PRIVATE -Werror)
target_compile_features(math_lib PRIVATE cxx_std_11)
