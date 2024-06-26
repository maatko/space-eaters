#include "scene.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#include <data.h>
#include <entity/entity.h>

#define PLAYER_WIDTH 32
#define PLAYER_HEIGHT 32

#define MIN(a, b) ((a < b) ? b : a)
#define MAX(a, b) ((a > b) ? b : a)

static void on_collide(entity_t* entity, entity_t* target)
{
    component_t* target_renderer = entity_component_get(target, render_component);
    component_t* entity_renderer = entity_component_get(entity, render_component);
    if (target_renderer == NULL || entity_renderer == NULL)
        return;


    const sprite_t* target_sprite = (const sprite_t*) target_renderer->data;
    const sprite_t* entity_sprite = (const sprite_t*) entity_renderer->data;
    if (target_sprite == NULL || entity_sprite == NULL)
        return;

    if (entity_sprite == &spritesheet.sprites.bomb)
    {
        if (target_sprite != &spritesheet.sprites.player_still)
            return;
        
        data.score += 500;
        data.bombs++;

        entity_delete(entity);
        return;
    }
  
    if (entity_sprite == &spritesheet.sprites.heart)
    {
        if (target_sprite != &spritesheet.sprites.player_still)
            return;
        
        data.score += 1000;
        data.hearts++;

        entity_delete(entity);
        return;
    }

    if (target_sprite == &spritesheet.sprites.enemy_yellow)
    {
        data.score += 100;

        if ((rand() / (float)RAND_MAX) <= 0.25f)
        {
            entity_t* bomb = entity_add(entity->pos_x, entity->pos_y, PLAYER_WIDTH / 1.5f, PLAYER_HEIGHT / 1.5f);
            {
                entity_component_add(bomb, render_component, (void*)&spritesheet.sprites.bomb);
                entity_component_add(bomb, gravity_component, (void*)&data.speed.bomb);
                entity_component_add(bomb, collision_component, NULL);
            }
        }

        if ((rand() / (float)RAND_MAX) <= 0.15f)
        {
            entity_t* bomb = entity_add(entity->pos_x, entity->pos_y, PLAYER_WIDTH / 1.5f, PLAYER_HEIGHT / 1.5f);
            {
                entity_component_add(bomb, render_component, (void*)&spritesheet.sprites.heart);
                entity_component_add(bomb, gravity_component, (void*)&data.speed.bomb);
                entity_component_add(bomb, collision_component, NULL);
            }
        }

        entity_delete(entity);
        entity_delete(target);
    }
}

static void on_show(float screen_width, float screen_height)
{
    srand((unsigned int)time(NULL));

    data.score = 0;
    data.hearts = 1;
    data.bombs = 0;

    data.on_collide = on_collide;

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
                entity_component_add(star, gravity_component, (void*)&data.speed.star);
            }
            x_offset += star_width + star_padding;
        }
    }

    entity_t* player = entity_add((screen_width - PLAYER_WIDTH) / 2.0f, screen_height - PLAYER_HEIGHT * 1.5f, PLAYER_WIDTH, PLAYER_HEIGHT);
    {
        entity_component_add(player, render_component, (void*) &spritesheet.sprites.player_still);
        entity_component_add(player, controller_component, (void*)&data.speed.player);
    }
}

static bool on_update(float screen_width, float screen_height, float frame_time)
{
    if (IsKeyPressed(KEY_ESCAPE))
        return scene_show(&menu_scene);

    if (data.hearts <= 0) 
        return scene_show(&over_scene);

    data.score += 2.5f * frame_time;

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
        sprintf(info_display, "%d", data.hearts);
        const float display_width = (float) MeasureText(info_display, info_font_size);

        const sprite_t* heart_sprite = &spritesheet.sprites.heart;
        
        const float heart_width = heart_sprite->width * 3.0f; 
        const float heart_height = heart_sprite->height * 3.0f;
      
        spritesheet_draw(
            heart_sprite,
            (side_frame_width - heart_width + side_frame_padding) / 2.0f - (heart_width + display_width / 2.0f) / 2.0f,
            (frame_height - heart_height) / 2.0f,
            heart_width,
            heart_height,
            0
        );

        DrawText(
            info_display,
            (side_frame_width - display_width + side_frame_padding) / 2.0f + (heart_width + display_width / 2.0f) / 2.0f,
            (frame_height - info_font_size) / 2.0f,
            info_font_size,
            GREEN
        );
    }

    // middle panel
    spritesheet_draw(&spritesheet.sprites.frame_full, side_frame_width + side_frame_padding, 0, full_frame_width, frame_height, 0);
    {
        sprintf(info_display, "%d", (int)data.score);
        DrawText(
            info_display,
            (screen_width - (float) MeasureText(info_display, info_font_size)) / 2.0f,
            (frame_height - info_font_size) / 2.0f,
            info_font_size,
            GREEN
        );
    }

    // right panel
    spritesheet_draw(&spritesheet.sprites.frame_right, side_frame_width + side_frame_padding * 2.0f + full_frame_width, 0, side_frame_width, frame_height, 0);
    {
        sprintf(info_display, "%d", data.bombs);
        const float display_width = (float) MeasureText(info_display, info_font_size);

        const sprite_t* bomb_sprite = &spritesheet.sprites.bomb;

        const float bomb_width = bomb_sprite->width * 3.5f;
        const float bomb_height = bomb_sprite->height * 3.5f;

        spritesheet_draw(
            bomb_sprite,
            screen_width - (side_frame_width + display_width + side_frame_padding) / 2.0f + (bomb_width + display_width / 2.0f) / 2.0f,
            (frame_height - bomb_height) / 2.0f,
            bomb_width,
            bomb_height,
            0
        );

        DrawText(
            info_display,
            screen_width - (side_frame_width + display_width + side_frame_padding) / 2.0f - (bomb_width + display_width / 2.0f) / 2.0f,
            (frame_height - info_font_size) / 2.0f,
            info_font_size,
            GREEN
        );
    }

    static float spawn_timer = 0.0f;
    if (spawn_timer >= 1.0f)
    {
        static const float enemy_width = PLAYER_WIDTH / 1.5f;
        static const float enemy_height = PLAYER_HEIGHT / 1.5f;

        entity_t* enemy = entity_add((rand() / (float) RAND_MAX) * (screen_width - (enemy_width * 1.5f)), frame_height - enemy_height, enemy_width, enemy_height);
        {
            entity_component_add(enemy, render_component, (void*)&spritesheet.sprites.enemy_yellow);
            entity_component_add(enemy, gravity_component, (void*)&data.speed.enemy);
        }
        spawn_timer = 0;
    }
    spawn_timer += MAX(1.0f, MIN(0.25f, 1.0f * (data.score / 1000.0f))) * frame_time;

    return false;
}

const scene_t game_scene =
{
    .on_show    = on_show,
    .on_update  = on_update,
    .on_hide    = NULL
};