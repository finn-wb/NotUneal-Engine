cmake_minimum_required(VERSION 3.16)
project(NotUnealComponents)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(NotUnealComponents STATIC
    MeshComponent.h
    MeshComponent.cpp
    LightComponent.h
    LightComponent.cpp
)

target_include_directories(NotUnealComponents PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/..")
target_link_libraries(NotUnealComponents PUBLIC NotUnealScene NotUnealRendering)
