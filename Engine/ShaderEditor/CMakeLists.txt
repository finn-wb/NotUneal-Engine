cmake_minimum_required(VERSION 3.16)
project(NotUnealShaderEditor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(NotUnealShaderEditor STATIC
    ShaderNode.h
    ShaderNode.cpp
    ShaderNodes.h
    ShaderNodes.cpp
    ShaderGraph.h
    ShaderGraph.cpp
)

target_include_directories(NotUnealShaderEditor PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/..")
target_link_libraries(NotUnealShaderEditor PUBLIC NotUnealCore NotUnealRendering)
