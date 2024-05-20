#include "sprite.h"

#include "spritesheet.h"

const Sprite *Sprite::BOSS = new Sprite(41, 74, 30, 23);
const Sprite *Sprite::LOGO = new Sprite(73, 74, 47, 23);

const Sprite *Sprite::HEART = new Sprite(51, 20, 8, 7);
const Sprite *Sprite::BOMB = new Sprite(121, 9, 6, 7);

const Sprite *Sprite::FRAME_LEFT = new Sprite(1, 106, 31, 22);
const Sprite *Sprite::FRAME_FULL = new Sprite(32, 106, 64, 22);
const Sprite *Sprite::FRAME_RIGHT = new Sprite(96, 106, 31, 22);

Sprite::Sprite(float u, float v, float width, float height) {
    m_PositionX = u;
    m_PositionY = v;

    m_Width = width;
    m_Height = height;
}

void Sprite::Draw(float x, float y, float width, float height, float rotation) const {
    SpriteSheet::Get()->DrawSprite(
            x, y,
            m_PositionX, m_PositionY,
            width, height,
            m_Width, m_Height,
            rotation
    );
}

float Sprite::GetWidth() const {
    return m_Width;
}

float Sprite::GetHeight() const {
    return m_Height;
}

