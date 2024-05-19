//
// Created by mat on 5/19/2024.
//

#include "controller.h"

ControllerComponent::ControllerComponent(float movement_speed) {
    m_MovementSpeed = movement_speed;
}

void ControllerComponent::OnUpdate(float sc_width, float sc_height, float frame_time) {
    if (IsKeyDown(KEY_RIGHT)) {
        *(m_EntityPositionX) += m_MovementSpeed * frame_time;
    }
    if (IsKeyDown(KEY_LEFT)) {
        *(m_EntityPositionX) -= m_MovementSpeed * frame_time;
    }
}
