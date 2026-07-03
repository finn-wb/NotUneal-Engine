cmake_minimum_required(VERSION 3.16)
project(NotUnealExamples)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Example 1: Simple Scene
add_executable(SimpleSceneExample SimpleScene.cpp)
target_link_libraries(SimpleSceneExample PRIVATE NotUnealEngine)
target_include_directories(SimpleSceneExample PRIVATE ${CMAKE_SOURCE_DIR})

# Example 2: Shader Editor
add_executable(ShaderEditorExample ShaderEditorExample.cpp)
target_link_libraries(ShaderEditorExample PRIVATE NotUnealEngine NotUnealShaderEditor)
target_include_directories(ShaderEditorExample PRIVATE ${CMAKE_SOURCE_DIR})

# Example 3: Asset Management
add_executable(AssetManagementExample AssetManagementExample.cpp)
target_link_libraries(AssetManagementExample PRIVATE NotUnealEngine NotUnealTools)
target_include_directories(AssetManagementExample PRIVATE ${CMAKE_SOURCE_DIR})
