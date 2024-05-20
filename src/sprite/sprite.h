//
// Created by mat on 5/20/2024.
//

#ifndef SPACE_EATERS_SPRITE_H
#define SPACE_EATERS_SPRITE_H

class Sprite {
public:
    Sprite(float u, float v, float width, float height);

public:
    void Draw(float x, float y, float width, float height, float rotation) const;

    float GetWidth() const;

    float GetHeight() const;

private:
    float m_PositionX;
    float m_PositionY;

    float m_Width;
    float m_Height;

public:
    static const Sprite *BOSS;
    static const Sprite *LOGO;

    static const Sprite *HEART;
    static const Sprite *BOMB;

    static const Sprite *FRAME_LEFT;
    static const Sprite *FRAME_FULL;
    static const Sprite *FRAME_RIGHT;
};

#endif //SPACE_EATERS_SPRITE_H
