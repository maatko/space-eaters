#ifndef SPACE_EATERS_ENTITY_H
#define SPACE_EATERS_ENTITY_H

#include <vector>

#include "component/component.h"

class Entity {
public:
    Entity(float x, float y, float width, float height);

    ~Entity();

public:
    void OnUpdate(float sc_width, float sc_height, float frame_time);

public:
    void AddComponent(Component *component);

    template<typename T>
    T *GetComponent() const {
        T *result = nullptr;
        for (auto currComp: m_Components) {
            result = dynamic_cast<T *>(currComp);
            if (result)
                break;
        }
        return result;
    }

protected:
    float m_PositionX;
    float m_PositionY;

    float m_Width;
    float m_Height;
private:
    std::vector<Component *> m_Components;
};

#endif //SPACE_EATERS_ENTITY_H
