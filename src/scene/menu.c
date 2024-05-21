#include "scene.h"

#include <stdio.h>
#include <math.h>

#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 50
#define BUTTON_PADDING 20

static void on_show(float screen_width, float screen_height) 
{
}

static bool on_update(float screen_width, float screen_height, float frame_time)
{
    float pos_x = (screen_width - BUTTON_WIDTH) / 2.0f;
    float pos_y = (screen_height - (BUTTON_HEIGHT + BUTTON_PADDING) * 2) / 2.0f;

    sprite_t boss_sprite = spritesheet.sprites.boss;
    {
        const float boss_width = boss_sprite.width * 5;
        const float boss_height = boss_sprite.height * 5;

        pos_y -= boss_height / 2.0f + BUTTON_PADDING * 3;
        {
            spritesheet_draw(&boss_sprite, (screen_width - boss_width) / 2.0f, pos_y, boss_width, boss_height, 0);
        }
        pos_y += boss_height;

        sprite_t logo_sprite = spritesheet.sprites.logo;
        {
            const float logo_width = logo_sprite.width * 1.25f;
            const float logo_height = logo_sprite.height * 1.25f;

            float animation = (float) 1.5f - fabs(sin((double) GetTime()));

            char anim[1024];
            sprintf(anim, "%lf", animation);

            DrawText(anim, 100, 100, 20, WHITE);

            spritesheet_draw(
                &logo_sprite, 
                (screen_width + boss_width - logo_width) / 2.0f, 
                pos_y, 
                logo_width * animation, 
                logo_height * animation,
                -25
            );
        }
        pos_y += BUTTON_PADDING * 3;
    }

    if (scene_button("Play", pos_x, pos_y, BUTTON_WIDTH, BUTTON_HEIGHT, 20))
    {
        return false;
    }
    pos_y += BUTTON_HEIGHT + BUTTON_PADDING;

    return scene_button("Quit", pos_x, pos_y, BUTTON_WIDTH, BUTTON_HEIGHT, 20);
}

static void on_hide()
{
}

scene_t menu_scene = {
    .on_show    = on_show,
    .on_update  = on_update,
    .on_hide    = on_hide
};