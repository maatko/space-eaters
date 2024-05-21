#include "scene.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#include <entity/entity.h>

#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 50
#define PADDING 20

static void on_show(float screen_width, float screen_height)
{
    srand((unsigned int)time(NULL));
}

static bool on_update(float screen_width, float screen_height, float frame_time)
{
    static float time = 0.0f;
    static float last_time = 0;

    if (time >= last_time)
    {
        static const float STAR_WIDTH = 3;
        static const float STAR_HEIGHT = 3;
        static const float STAR_PADDING = 10;

        // generates a random position on
        // the screen that can fit a star
        float pos_x = STAR_PADDING + (rand() / (float) RAND_MAX) * (screen_width - STAR_WIDTH - STAR_PADDING);
        float pos_y = STAR_PADDING + (rand() / (float) RAND_MAX) * (screen_height - STAR_HEIGHT - STAR_PADDING);

        entity_t* star = entity_add(pos_x, pos_y, STAR_WIDTH, STAR_HEIGHT);
        {
            confetti_t* confetti = (confetti_t*) malloc(sizeof(confetti_t));
            assert(confetti != NULL);

            confetti->scale = 0.0f;
            confetti->max_scale = 0.05f;
            confetti->speed = 0.05f;
            confetti->flip = false;

            entity_component_add(star, render_component, (void*)&spritesheet.sprites.star);
            entity_component_add(star, confetti_component, (void*)confetti);
        }

        time = 0;
        last_time = (rand() / (float) RAND_MAX) * 0.05f;
    }
    time += 1.0f * frame_time;

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

scene_t menu_scene =
{
    .on_show    = on_show,
    .on_update  = on_update,
    .on_hide    = NULL
};