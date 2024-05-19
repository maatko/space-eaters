//
// Created by mat on 5/19/2024.
//

#ifndef SPACE_EATERS_SPRITE_H
#define SPACE_EATERS_SPRITE_H

#include "component.h"

class SpriteComponent : public Component {
public:
    SpriteComponent(float u, float v, float tex_width, float tex_height);

protected:
    void OnUpdate(float sc_width, float sc_height, float frame_time) override;

public:
    void Rotate(float rotation);

protected:
    float m_SpriteX;
    float m_SpriteY;

    float m_SpriteWidth;
    float m_SpriteHeight;

    float m_SpriteRotation;
};

#endif //SPACE_EATERS_SPRITE_H
