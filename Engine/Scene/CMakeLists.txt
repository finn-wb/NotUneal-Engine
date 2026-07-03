cmake_minimum_required(VERSION 3.16)
project(NotUnealScene)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(NotUnealScene STATIC
    src/GameObject.h
    src/GameObject.cpp
    src/Component.h
    src/Component.cpp
    src/TransformComponent.h
    src/TransformComponent.cpp
    src/Scene.h
    src/Scene.cpp
    src/SceneManager.h
    src/SceneManager.cpp
)

target_include_directories(NotUnealScene PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_link_libraries(NotUnealScene PUBLIC NotUnealCore)
