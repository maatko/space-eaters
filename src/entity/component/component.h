//
// Created by mat on 5/19/2024.
//

#ifndef SPACE_EATERS_COMPONENT_H
#define SPACE_EATERS_COMPONENT_H

#include <raylib.h>

class Component {
protected:
    virtual void OnUpdate(float sc_width, float sc_height, float frame_time) {};

protected:
    float *m_EntityPositionX = nullptr;
    float *m_EntityPositionY = nullptr;

    float *m_EntityWidth = nullptr;
    float *m_EntityHeight = nullptr;
private:
    friend class Entity;
};

#endif //SPACE_EATERS_COMPONENT_H
