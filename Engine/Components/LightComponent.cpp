#include "LightComponent.h"

namespace NotUneal {

LightComponent::LightComponent()
    : mLightType(LightType::Directional),
      mColor(1.0f, 1.0f, 1.0f, 1.0f),
      mIntensity(1.0f),
      mRange(10.0f),
      mAngle(45.0f) {}

} // namespace NotUneal
