#include "ShaderNodes.h"
#include <sstream>

namespace NotUneal {

// VertexInputNode
VertexInputNode::VertexInputNode(InputType inputType)
    : ShaderNode(NodeType::Input, "VertexInput"), mInputType(inputType) {}

std::string VertexInputNode::GenerateGLSL() const {
    switch (mInputType) {
        case InputType::Position: return "in vec3 vPosition;";
        case InputType::Normal: return "in vec3 vNormal;";
        case InputType::Tangent: return "in vec3 vTangent;";
        case InputType::TexCoord: return "in vec2 vTexCoord;";
        case InputType::Color: return "in vec4 vColor;";
        default: return "";
    }
}

// TextureSamplerNode
TextureSamplerNode::TextureSamplerNode()
    : ShaderNode(NodeType::Texture, "TextureSampler"), mTextureName("texture0") {}

std::string TextureSamplerNode::GenerateGLSL() const {
    std::stringstream ss;
    ss << "uniform sampler2D " << mTextureName << ";";
    return ss.str();
}

// MathNode
MathNode::MathNode(MathOp op)
    : ShaderNode(NodeType::Math, "MathOp"), mOp(op) {}

std::string MathNode::GenerateGLSL() const {
    switch (mOp) {
        case MathOp::Add: return "vec4 result = input1 + input2;";
        case MathOp::Subtract: return "vec4 result = input1 - input2;";
        case MathOp::Multiply: return "vec4 result = input1 * input2;";
        case MathOp::Divide: return "vec4 result = input1 / input2;";
        case MathOp::Dot: return "float result = dot(input1, input2);";
        case MathOp::Cross: return "vec3 result = cross(input1, input2);";
        case MathOp::Normalize: return "vec3 result = normalize(input1);";
        case MathOp::Length: return "float result = length(input1);";
        case MathOp::Pow: return "vec4 result = pow(input1, input2);";
        case MathOp::Sqrt: return "vec4 result = sqrt(input1);";
        default: return "";
    }
}

// OutputNode
OutputNode::OutputNode()
    : ShaderNode(NodeType::Output, "Output") {}

std::string OutputNode::GenerateGLSL() const {
    return "out vec4 FragColor;";
}

// CustomGLSLNode
CustomGLSLNode::CustomGLSLNode()
    : ShaderNode(NodeType::Custom, "CustomGLSL"), mGLSLCode("") {}

std::string CustomGLSLNode::GenerateGLSL() const {
    return mGLSLCode;
}

} // namespace NotUneal
