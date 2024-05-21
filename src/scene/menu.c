#include "scene.h"

#include <stdio.h>
#include <math.h>

#include <entity/entity.h>

#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 50
#define PADDING 20

static bool on_update(float screen_width, float screen_height, float frame_time)
{
    float pos_x = (screen_width - BUTTON_WIDTH) / 2.0f;
    float pos_y = (screen_height - (BUTTON_HEIGHT + PADDING) * 2) / 2.0f;

    sprite_t boss_sprite = spritesheet.sprites.boss;
    {
        const float boss_width = boss_sprite.width * 5;
        const float boss_height = boss_sprite.height * 5;

        pos_y -= boss_height / 2.0f + PADDING * 3;
        {
            spritesheet_draw(&boss_sprite, (screen_width - boss_width) / 2.0f, pos_y, boss_width, boss_height, 0);
        }
        pos_y += boss_height;

        sprite_t logo_sprite = spritesheet.sprites.logo;
        {
            const float logo_width = logo_sprite.width * 1.25f;
            const float logo_height = logo_sprite.height * 1.25f;

            float animation = (float) 1.5f - fabs(sin((double) GetTime()));

            spritesheet_draw(
                &logo_sprite, 
                (screen_width + boss_width - logo_width) / 2.0f, 
                pos_y, 
                logo_width * animation, 
                logo_height * animation,
                -25
            );
        }
        pos_y += PADDING * 3;
    }

    DrawText("SpaceEaters was made whilst studying @ FERIT (2024)", 20, screen_height - 35, 15, GREEN);

    if (scene_button("Play", pos_x, pos_y, BUTTON_WIDTH, BUTTON_HEIGHT, 20))
        return scene_show(&game_scene);

    pos_y += BUTTON_HEIGHT + PADDING;

    return scene_button("Quit", pos_x, pos_y, BUTTON_WIDTH, BUTTON_HEIGHT, 20);
}

scene_t menu_scene = {
    .on_show    = NULL,
    .on_update  = on_update,
    .on_hide    = NULL
};