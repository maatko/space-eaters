//
// Created by mat on 5/19/2024.
//

#ifndef SPACE_EATERS_SPRITE_H
#define SPACE_EATERS_SPRITE_H

#include "component.h"

#include <unordered_map>

struct Sprite {
    float x;
    float y;

    float width;
    float height;

    float rotation;
};

class SpriteComponent : public Component {
public:
    enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        STILL
    };
public:
    SpriteComponent(Sprite top, Sprite left, Sprite bottom, Sprite right, Sprite still);

protected:
    void OnUpdate(float sc_width, float sc_height, float frame_time) override;

protected:
    std::unordered_map<SpriteComponent::Direction, Sprite> m_Sprites;
};

#endif //SPACE_EATERS_SPRITE_H
