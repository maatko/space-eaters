//
// Created by mat on 5/19/2024.
//

#ifndef SPACE_STRIKE_SPRITESHEET_H
#define SPACE_STRIKE_SPRITESHEET_H

#include <unordered_map>

#include <raylib.h>

#include "sprite.h"

class SpriteSheet {
private:
    explicit SpriteSheet(const char *texture_path);

    friend class Sprite;

public:
    void DrawSprite(float x, float y,
                    float u, float v,
                    float width, float height,
                    float tex_width, float tex_height,
                    float rotation);

private:
    Texture2D m_Texture = {0};

public:
    static void Initialize(const char *path);

    static SpriteSheet *Get();

    static void Clean();

private:
    static SpriteSheet *m_SpriteSheet;
};

#endif //SPACE_STRIKE_SPRITESHEET_H
