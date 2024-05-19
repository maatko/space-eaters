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

protected:
    float m_MovementSpeed;
};

#endif //SPACE_EATERS_CONTROLLER_H
