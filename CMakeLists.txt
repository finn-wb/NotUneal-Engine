cmake_minimum_required(VERSION 3.16)
project(NotUnealEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add subdirectories
add_subdirectory(Engine/Core)
add_subdirectory(Engine/Scene)
add_subdirectory(Engine/Rendering)
add_subdirectory(Engine/Components)

# Create main library
add_library(NotUnealEngine INTERFACE)
target_link_libraries(NotUnealEngine INTERFACE
    NotUnealCore
    NotUnealScene
    NotUnealRendering
    NotUnealComponents
)
