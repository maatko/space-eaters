//
// Created by mat on 5/19/2024.
//

#include "sprite.h"

#include <spritesheet.h>

SpriteComponent::SpriteComponent(float u, float v, float tex_width, float tex_height) {
    m_SpriteX = u;
    m_SpriteY = v;

    m_SpriteWidth = tex_width;
    m_SpriteHeight = tex_height;

    m_SpriteRotation = 0;
}

void SpriteComponent::OnUpdate(float sc_width, float sc_height, float frame_time) {
    SpriteSheet::Get()->DrawSprite(
            *m_EntityPositionX, *m_EntityPositionY,
            m_SpriteX, m_SpriteY,
            *m_EntityWidth, *m_EntityHeight,
            m_SpriteWidth, m_SpriteHeight,
            m_SpriteRotation
    );
}

void SpriteComponent::Rotate(float rotation) {
    m_SpriteRotation = rotation;
}

