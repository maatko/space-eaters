#include "scene.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#include <entity/entity.h>

#define PLAYER_WIDTH 32
#define PLAYER_HEIGHT 32

struct
{
    float score;

    int hearts;
    int bombs;

    float player_speed;
    float star_speed;
} statistics;

static void on_show(float screen_width, float screen_height)
{
    srand((unsigned int)time(NULL));

    // reset all the statistics
    statistics.score = 0;
    statistics.hearts = 0;
    statistics.bombs = 0;

    statistics.player_speed = 250.0f;
    statistics.star_speed = 150.0f;

    const sprite_t* star_sprite = &spritesheet.sprites.star;
    {
        const float star_width = star_sprite->width;
        const float star_height = star_sprite->height;
        const float star_padding = 5;

        const int star_count = (screen_width / (star_width + star_padding));

        float x_offset = star_padding / 2.0f;
        for(int i = 0; i < star_count; i++)
        {
            entity_t* star = entity_add(x_offset, screen_height * 0.2f + (rand() / (float) RAND_MAX) * 500.0f, star_width, star_height);
            {
                entity_component_add(star, render_component, (void*)star_sprite);
                entity_component_add(star, gravity_component, (void*)&statistics.star_speed);
            }
            x_offset += star_width + star_padding;
        }
    }

    entity_t* player = entity_add((screen_width - PLAYER_WIDTH) / 2.0f, screen_height - PLAYER_HEIGHT * 1.5f, PLAYER_WIDTH, PLAYER_HEIGHT);
    {
        entity_component_add(player, render_component, (void*) &spritesheet.sprites.player_still);
        entity_component_add(player, controller_component, (void*)&statistics.player_speed);
    }
}

static bool on_update(float screen_width, float screen_height, float frame_time)
{
    if (IsKeyPressed(KEY_ESCAPE))
        return scene_show(&menu_scene);

    statistics.score += 2.5f * frame_time;

    float side_frame_padding = screen_width * 0.015f;
    float side_frame_width = screen_width * 0.25f;
    float full_frame_width = screen_width - (side_frame_width + side_frame_padding) * 2.0f;
    float frame_height = screen_height * 0.2f;    

    // make sure to black out the background
    // of the HUD since the textures have
    // transparancy in them
    DrawRectangle(0, 0, screen_width, frame_height, BLACK);

    char info_display[1024];
    static const int info_font_size = 30;

    // left panel
    spritesheet_draw(&spritesheet.sprites.frame_left, 0, 0, side_frame_width, frame_height, 0);
    {
        sprintf(info_display, "%d", statistics.hearts);
        DrawText(
            info_display,
            (side_frame_width - MeasureText(info_display, info_font_size) + side_frame_padding) / 2.0f,
            (frame_height - info_font_size) / 2.0f,
            info_font_size,
            GREEN
        );
    }

    // middle panel
    spritesheet_draw(&spritesheet.sprites.frame_full, side_frame_width + side_frame_padding, 0, full_frame_width, frame_height, 0);
    {
        sprintf(info_display, "%d", (int)statistics.score);
        DrawText(
            info_display,
            (screen_width - MeasureText(info_display, info_font_size)) / 2.0f,
            (frame_height - info_font_size) / 2.0f,
            info_font_size,
            GREEN
        );
    }

    // right panel
    spritesheet_draw(&spritesheet.sprites.frame_right, side_frame_width + side_frame_padding * 2.0f + full_frame_width, 0, side_frame_width, frame_height, 0);
    {
        sprintf(info_display, "%d", statistics.bombs);
        DrawText(
            info_display,
            screen_width - (side_frame_width + MeasureText(info_display, info_font_size) + side_frame_padding) / 2.0f,
            (frame_height - info_font_size) / 2.0f,
            info_font_size,
            GREEN
        );
    }

    return false;
}

scene_t game_scene =
{
    .on_show    = on_show,
    .on_update  = on_update,
    .on_hide    = NULL
};