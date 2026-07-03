cmake_minimum_required(VERSION 3.16)
project(NotUnealCore)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(NotUnealCore STATIC
    src/Core.h
    src/Types.h
    src/Memory.h
    src/Containers/Array.h
    src/Containers/Map.h
    src/Containers/String.h
)

target_include_directories(NotUnealCore PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
