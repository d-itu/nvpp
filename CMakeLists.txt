cmake_minimum_required(VERSION 3.15)

project(nvpp)

add_library(nvpp INTERFACE)
target_include_directories(nvpp INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(nvpp INTERFACE cxx_std_23)
