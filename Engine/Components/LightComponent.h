#pragma once

#include "Scene/Component.h"
#include "Core/Types.h"
#include <memory>

namespace NotUneal {

enum class LightType {
    Directional,
    Point,
    Spot
};

/**
 * Light component for illuminating scenes.
 */
class NOTUNEAL_EXPORT LightComponent : public Component {
public:
    LightComponent();
    ~LightComponent() override = default;
    
    void SetLightType(LightType type) { mLightType = type; }
    LightType GetLightType() const { return mLightType; }
    
    void SetColor(const Color& color) { mColor = color; }
    Color GetColor() const { return mColor; }
    
    void SetIntensity(float intensity) { mIntensity = intensity; }
    float GetIntensity() const { return mIntensity; }
    
    void SetRange(float range) { mRange = range; }
    float GetRange() const { return mRange; }
    
    void SetAngle(float angle) { mAngle = angle; }
    float GetAngle() const { return mAngle; }
    
    std::string GetComponentName() const override { return "LightComponent"; }
    
private:
    LightType mLightType;
    Color mColor;
    float mIntensity;
    float mRange;
    float mAngle;
};

} // namespace NotUneal
