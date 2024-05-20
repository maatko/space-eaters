//
// Created by mat on 5/20/2024.
//

#include "gravity.h"

GravityComponent::GravityComponent(float intensity) {
    m_GravityIntensity = intensity;
}

void GravityComponent::OnUpdate(float sc_width, float sc_height, float frame_time) {
    (*m_EntityPositionY) += m_GravityIntensity * frame_time;
}

