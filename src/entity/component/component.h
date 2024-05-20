#ifndef SPACE_EATERS_COMPONENT_H
#define SPACE_EATERS_COMPONENT_H

#include <vector>
#include <raylib.h>

class Entity;

class Screen;

class Component {
protected:
    virtual void OnUpdate(float sc_width, float sc_height, float frame_time) {};

protected:
    Entity *m_Entity = nullptr;
    Screen *m_Screen = nullptr;

    float *m_EntityPositionX = nullptr;
    float *m_EntityPositionY = nullptr;

    float *m_EntityWidth = nullptr;
    float *m_EntityHeight = nullptr;
private:
    friend class Entity;
};

#endif //SPACE_EATERS_COMPONENT_H
