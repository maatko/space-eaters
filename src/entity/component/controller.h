//
// Created by mat on 5/19/2024.
//

#ifndef SPACE_EATERS_CONTROLLER_H
#define SPACE_EATERS_CONTROLLER_H

#include "component.h"

class ControllerComponent : public Component {
public:
    explicit ControllerComponent(float movement_speed);

public:
    void OnUpdate(float sc_width, float sc_height, float frame_time) override;

    float GetMotionX() const;

    float GetMotionY() const;

protected:
    float m_MovementSpeed;

    float m_MotionX;
    float m_MotionY;
};

#endif //SPACE_EATERS_CONTROLLER_H
