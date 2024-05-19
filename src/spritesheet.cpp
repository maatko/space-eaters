//
// Created by mat on 5/19/2024.
//

#include <spritesheet.h>

SpriteSheet::SpriteSheet(const char *texture_path) {
    m_Texture = LoadTexture(texture_path);
}

void SpriteSheet::DrawSprite(float x, float y, float u, float v, float width, float height, float tex_width,
                             float tex_height, float rotation) {
    DrawTexturePro(
            m_Texture,
            {u, v, tex_width, tex_height},
            {x, y, width, height},
            {0, 0},
            rotation,
            WHITE
    );
}