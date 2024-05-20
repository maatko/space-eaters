//
// Created by mat on 5/19/2024.
//

#include "controller.h"

#include "../entity.h"

#include "gravity.h"
#include "particle.h"

#include <screen/screen.h>

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

    if (IsKeyPressed(KEY_UP) && !IsKeyPressedRepeat(KEY_UP)) {
        auto bullet = new Entity(*m_EntityPositionX + ((*m_EntityWidth) - 2) / 2.0f, *m_EntityPositionY, 2, 3);

        m_Screen->AddEntity(bullet);

        {
            bullet->AddComponent(new GravityComponent(-150, false));
            bullet->AddComponent(new ParticleComponent(Sprite::BULLET));
        }
    }

    *(m_EntityPositionX) += m_MotionX;
}

float ControllerComponent::GetMotionX() const {
    return m_MotionX;
}

float ControllerComponent::GetMotionY() const {
    return m_MotionY;
}
