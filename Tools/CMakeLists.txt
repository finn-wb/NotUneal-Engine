cmake_minimum_required(VERSION 3.16)
project(NotUnealTools)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Optional: Assimp for mesh importing
# find_package(assimp REQUIRED)

add_library(NotUnealTools STATIC
    BuildTools.h
    BuildTools.cpp
)

target_include_directories(NotUnealTools PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/..")
target_link_libraries(NotUnealTools PUBLIC NotUnealEngine)
# target_link_libraries(NotUnealTools PUBLIC assimp)
