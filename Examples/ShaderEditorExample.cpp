# Example: Using the Shader Editor

This example demonstrates creating a custom shader using the visual node system.

```cpp
#include <NotUneal/Engine.h>
#include <NotUneal/ShaderEditor/ShaderGraph.h>
#include <NotUneal/ShaderEditor/ShaderNodes.h>
#include <iostream>

using namespace NotUneal;

int main() {
    // Create a shader graph
    ShaderGraph shaderGraph("NormalVisualizer");
    
    // Add input node for vertex normal
    auto normalInput = std::make_shared<VertexInputNode>(
        VertexInputNode::InputType::Normal);
    shaderGraph.AddNode(normalInput);
    
    // Add math node to transform normal to color
    // Normal [-1,1] -> Color [0,1]
    auto mathNode = std::make_shared<MathNode>(MathNode::MathOp::Multiply);
    shaderGraph.AddNode(mathNode);
    
    // Add output node
    auto outputNode = std::make_shared<OutputNode>();
    shaderGraph.AddNode(outputNode);
    
    // Connect nodes
    mathNode->ConnectInput(0, normalInput->GetNodeID(), 0);
    outputNode->ConnectInput(0, mathNode->GetNodeID(), 0);
    
    // Compile shader graph
    std::string vertexShader, fragmentShader;
    if (!shaderGraph.Compile(vertexShader, fragmentShader)) {
        std::cerr << "Shader compilation failed" << std::endl;
        return -1;
    }
    
    std::cout << "Vertex Shader:" << std::endl;
    std::cout << vertexShader << std::endl;
    
    std::cout << "\nFragment Shader:" << std::endl;
    std::cout << fragmentShader << std::endl;
    
    // Create shader program from compiled code
    auto vShader = std::make_shared<Shader>(Shader::Type::Vertex, vertexShader);
    auto fShader = std::make_shared<Shader>(Shader::Type::Fragment, fragmentShader);
    
    if (!vShader->Compile() || !fShader->Compile()) {
        std::cerr << "Failed to compile generated shaders" << std::endl;
        return -1;
    }
    
    auto program = std::make_shared<ShaderProgram>();
    program->AttachShader(vShader);
    program->AttachShader(fShader);
    if (!program->Link()) {
        std::cerr << "Failed to link shader program" << std::endl;
        return -1;
    }
    
    // Create material from shader
    auto material = std::make_shared<Material>(program);
    
    std::cout << "\nShader created successfully!" << std::endl;
    std::cout << "Program ID: " << program->GetHandle() << std::endl;
    
    return 0;
}
```

Compile with:
```bash
g++ -std=c++17 -I./Engine example_shader.cpp -o example_shader -lNotUnealEngine
```
