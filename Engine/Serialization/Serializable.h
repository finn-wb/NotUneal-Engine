#pragma once

#include "Archive.h"
#include <memory>
#include <string>
#include <vector>

namespace NotUneal {

class Serializable {
public:
    virtual ~Serializable() = default;
    virtual void Serialize(Archive& ar) = 0;
    virtual void Deserialize(Archive& ar) = 0;
};

} // namespace NotUneal
