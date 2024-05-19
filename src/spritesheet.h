//
// Created by mat on 5/19/2024.
//

#ifndef SPACE_STRIKE_SPRITESHEET_H
#define SPACE_STRIKE_SPRITESHEET_H

#include <raylib.h>
#include <unordered_map>

class SpriteSheet {
public:
    explicit SpriteSheet(const char *texture_path);

public:
    void DrawSprite(float x, float y,
                    float u, float v,
                    float width, float height,
                    float tex_width, float tex_height,
                    float rotation);

private:
    Texture2D m_Texture = {0};
};

#endif //SPACE_STRIKE_SPRITESHEET_H
