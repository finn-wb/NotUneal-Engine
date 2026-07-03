# Shader Editor Guide

## Creating Shaders Visually

The shader editor provides a node-based interface for creating shaders without writing GLSL directly.

## Available Nodes

### Input Nodes
Provide vertex data to your shader:
- **Position**: 3D vertex position
- **Normal**: Vertex normal
- **Tangent**: Vertex tangent
- **TexCoord**: Texture coordinates (UV)
- **Color**: Vertex color

### Texture Nodes
- **Texture Sampler**: Sample 2D textures
- Supports multiple texture slots
- Configurable filtering and wrapping

### Math Nodes
- **Add**: Vector/scalar addition
- **Subtract**: Vector/scalar subtraction
- **Multiply**: Vector/scalar multiplication
- **Divide**: Vector/scalar division
- **Dot**: Vector dot product
- **Cross**: Vector cross product
- **Normalize**: Normalize vector
- **Length**: Vector length
- **Pow**: Power operation
- **Sqrt**: Square root
- **Min/Max**: Minimum/maximum
- **Clamp**: Clamp to range
- **Lerp**: Linear interpolation

### Output Node
- Final color output (FragColor)
- Alpha value
- Normal output (for normal maps)

### Custom Nodes
- Write arbitrary GLSL code
- Mix with node graph
- Reusable custom node graphs

## Example: Normal Map Shader

1. Add **TexCoord** input node
2. Add **Texture Sampler** node for normal map
3. Connect TexCoord → Texture Sampler
4. Add **Output** node
5. Connect Texture Sampler → Output
6. Compile and use

## Example: Parallax Mapped Surface

1. Input: Position, Normal, TexCoord, Tangent
2. Texture: Diffuse map, Normal map, Height map
3. Math: Calculate parallax offset
4. Math: Apply to UVs
5. Sample final textures
6. Output: Final color

## Graph Properties

Each shader graph has:
- **Name**: Identifier
- **Version**: For asset tracking
- **Tags**: For material system
- **Properties**: Exposed uniforms

## Exporting Shaders

```cpp
ShaderGraph graph("MyShader");
// ... add nodes ...

std::string vertex, fragment;
if (graph.Compile(vertex, fragment)) {
    // Save or use directly
    std::ofstream file("MyShader.glsl");
    file << vertex << "\n\n" << fragment;
}
```

## Performance Considerations

- Keep node count reasonable for performance
- Avoid expensive operations in fragment shaders
- Use texture compression where possible
- Bake complex calculations when feasible
- Profile on target hardware

## Shader Debugging

- Visual preview in editor
- Compilation error messages
- Node value visualization
- Real-time material preview

## Advanced: Custom Node Types

```cpp
class ProceduralNoiseNode : public ShaderNode {
public:
    ProceduralNoiseNode() : ShaderNode(NodeType::Custom, "PerlinNoise") {}
    
    std::string GenerateGLSL() const override {
        return R"(
            vec4 noise = vec4(perlin_noise(input_uv), 
                             perlin_noise(input_uv + 1.0),
                             perlin_noise(input_uv + 2.0), 1.0);
        )";
    }
};
```
