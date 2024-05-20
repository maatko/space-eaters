//
// Created by mat on 5/20/2024.
//

#include "gravity.h"

#include <screen/screen.h>

GravityComponent::GravityComponent(float intensity, bool reset_position) {
    m_GravityIntensity = intensity;
    m_ResetPosition = reset_position;
}

void GravityComponent::OnUpdate(float sc_width, float sc_height, float frame_time) {
    (*m_EntityPositionY) += m_GravityIntensity * frame_time;

    if ((*m_EntityPositionY) + (*m_EntityHeight) >= sc_height || (*m_EntityPositionY) < 0) {
        if (m_ResetPosition) {
            *m_EntityPositionY = 0;
        } else {
            m_Screen->RemoveEntity(m_Entity);
        }
    }
}
