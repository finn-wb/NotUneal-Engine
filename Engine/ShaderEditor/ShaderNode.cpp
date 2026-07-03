#include "ShaderNode.h"
#include <random>

namespace NotUneal {

static uint32_t gNodeIDCounter = 0;

ShaderNode::ShaderNode(NodeType type, const std::string& name)
    : mType(type), mName(name), mNodeID(gNodeIDCounter++) {}

void ShaderNode::ConnectInput(uint32_t inputSlot, uint32_t sourceNodeID, uint32_t sourceOutputSlot) {
    if (inputSlot >= mConnections.size()) {
        mConnections.resize(inputSlot + 1);
    }
    mConnections[inputSlot] = {sourceNodeID, sourceOutputSlot};
}

void ShaderNode::DisconnectInput(uint32_t inputSlot) {
    if (inputSlot < mConnections.size()) {
        mConnections[inputSlot] = {0, 0};
    }
}

} // namespace NotUneal
