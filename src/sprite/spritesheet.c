#include "spritesheet.h"

spritesheet_t spritesheet = {
    .sprites = {
        .logo           = { 73, 74, 47, 23  },
        .frame_left     = { 1, 106, 31, 22  },
        .frame_full     = { 32, 106, 64, 22 },
        .frame_right    = { 96, 106, 31, 22 },
        .player_left    = { 9, 1, 7, 7      },
        .player_still   = { 0, 1, 8, 7      },
        .player_right   = { 0, 34, 8, 7     },
        .enemy_green    = { 24, 33, 8, 7    },
        .enemy_red      = { 40, 33, 8, 7    },
        .enemy_yellow   = { 56, 33, 8, 7    },
        .boss           = { 41, 74, 30, 23  },
        .heart          = { 51, 20, 8, 7    },
        .bomb           = { 121, 9, 6, 7    },
        .bullet         = { 19, 52, 2, 3    },
        .star           = { 2, 88, 3, 3     },
        .explode        = { 16, 65, 8, 8    }
    }
};

void spritesheet_load(const char* path)
{
    Texture2D texture = LoadTexture(path);
    {
        spritesheet.width = texture.width;
        spritesheet.height = texture.height;
    }
    spritesheet.texture = texture;
}

void spritesheet_draw(const sprite_t* sprite, float x, float y, float width, float height, float rotation)
{
    DrawTexturePro(
        spritesheet.texture,
        *sprite,
        (Rectangle) { x, y, width, height },
        (Vector2) { 0, 0 },
        rotation,
        WHITE
    );
}

void spritesheet_free()
{
    UnloadTexture(spritesheet.texture);
}