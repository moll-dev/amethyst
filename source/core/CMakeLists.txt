add_library(core SHARED
    source/geometry.cpp)

target_include_directories(core
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_options(core PRIVATE -Werror)
target_compile_features(core PRIVATE cxx_std_11)
