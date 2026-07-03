#pragma once

#include "ShaderNode.h"

namespace NotUneal {

/**
 * Input node - provides vertex data (position, normal, texcoord, etc.)
 */
class VertexInputNode : public ShaderNode {
public:
    enum class InputType {
        Position,
        Normal,
        Tangent,
        TexCoord,
        Color
    };
    
    VertexInputNode(InputType inputType);
    
    InputType GetInputType() const { return mInputType; }
    std::string GenerateGLSL() const override;
    
private:
    InputType mInputType;
};

/**
 * Texture sampling node
 */
class TextureSamplerNode : public ShaderNode {
public:
    TextureSamplerNode();
    
    void SetTextureName(const std::string& name) { mTextureName = name; }
    const std::string& GetTextureName() const { return mTextureName; }
    
    std::string GenerateGLSL() const override;
    
private:
    std::string mTextureName;
};

/**
 * Math operation node (Add, Multiply, Dot, etc.)
 */
class MathNode : public ShaderNode {
public:
    enum class MathOp {
        Add,
        Subtract,
        Multiply,
        Divide,
        Dot,
        Cross,
        Normalize,
        Length,
        Pow,
        Sqrt
    };
    
    MathNode(MathOp op);
    
    MathOp GetOperation() const { return mOp; }
    std::string GenerateGLSL() const override;
    
private:
    MathOp mOp;
};

/**
 * Output node - final color output
 */
class OutputNode : public ShaderNode {
public:
    OutputNode();
    
    std::string GenerateGLSL() const override;
};

/**
 * Custom GLSL code node
 */
class CustomGLSLNode : public ShaderNode {
public:
    CustomGLSLNode();
    
    void SetGLSLCode(const std::string& code) { mGLSLCode = code; }
    const std::string& GetGLSLCode() const { return mGLSLCode; }
    
    std::string GenerateGLSL() const override;
    
private:
    std::string mGLSLCode;
};

} // namespace NotUneal
