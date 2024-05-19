//
// Created by mat on 5/19/2024.
//

#include "controller.h"
#include "sprite.h"

#include "../entity.h"

ControllerComponent::ControllerComponent(float movement_speed) {
    m_MovementSpeed = movement_speed;

    m_MotionX = 0.0f;
    m_MotionY = 0.0f;
}

void ControllerComponent::OnUpdate(float sc_width, float sc_height, float frame_time) {
    if (IsKeyDown(KEY_RIGHT)) {
        m_MotionX = m_MovementSpeed * frame_time;
    } else if (IsKeyDown(KEY_LEFT)) {
        m_MotionX = -m_MovementSpeed * frame_time;
    } else {
        m_MotionX = 0;
    }

    *(m_EntityPositionX) += m_MotionX;
}

float ControllerComponent::GetMotionX() const {
    return m_MotionX;
}

float ControllerComponent::GetMotionY() const {
    return m_MotionY;
}
