cmake_minimum_required(VERSION 3.16)
project(NotUnealEditor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Editor requires Qt for UI
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

add_library(NotUnealEditor STATIC
    ProjectSettings.h
    ProjectSettings.cpp
    EditorViewport.h
    EditorViewport.cpp
    Editor.h
    Editor.cpp
)

target_include_directories(NotUnealEditor PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/..")
target_link_libraries(NotUnealEditor PUBLIC
    NotUnealEngine
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)
