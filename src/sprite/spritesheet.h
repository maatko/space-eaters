#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <raylib.h>
typedef Rectangle sprite_t;

typedef struct
{
    const struct 
    {
        const sprite_t logo;

        const sprite_t frame_left;
        const sprite_t frame_full;
        const sprite_t frame_right;

        const sprite_t player_left;
        const sprite_t player_still;
        const sprite_t player_right;

        const sprite_t enemy_green;
        const sprite_t enemy_red;
        const sprite_t enemy_yellow;

        const sprite_t boss;

        const sprite_t heart;
        const sprite_t bomb;
        const sprite_t bullet;
        const sprite_t star;
    } sprites;

    Texture2D texture;

    float width;
    float height;
} spritesheet_t;

void spritesheet_load(const char* path);

void spritesheet_draw(const sprite_t* sprite, float x, float y, float width, float height, float rotation);

void spritesheet_free();

extern spritesheet_t spritesheet;

#endif //SPRITESHEET_H