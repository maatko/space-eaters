#include "scene.h"

#include <stdio.h>
#include <raylib.h>

#include <entity/entity.h>

static const scene_t* current_scene = NULL;

bool scene_show(const scene_t* scene)
{
    if (current_scene != NULL && current_scene->on_hide != NULL)
        current_scene->on_hide();

    entity_free();

    if (scene->on_show != NULL && scene->on_show != NULL)
        scene->on_show(GetScreenWidth(), GetScreenHeight());

    current_scene = scene;

    return false; 
}

bool scene_update(float screen_width, float screen_height, float frame_time)
{
    if (current_scene == NULL)
        return false;
    
    return current_scene->on_update(screen_width, screen_height, frame_time);
}

bool scene_button(const char* text, float x, float y, float width, float height, int font_size)
{
    spritesheet_draw(&spritesheet.sprites.frame_full, x, y, width, height, 0);

    bool hovered = CheckCollisionPointRec(GetMousePosition(), (Rectangle){ x, y, width, height });
    {
        DrawText(
            text,
            (int) (x + (width - (float) MeasureText(text, (int) font_size)) / 2.0f),
            (int) (y + (height - font_size) / 2.0f), (int) font_size,
            hovered ? GREEN : WHITE
        );
    }
    
    return IsMouseButtonDown(MOUSE_BUTTON_LEFT) && hovered;
}

void scene_free()
{
    if (current_scene == NULL)
        return;
    
    if (current_scene->on_hide != NULL)
        current_scene->on_hide();

    current_scene = NULL;
}