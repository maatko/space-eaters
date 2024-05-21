#include "scene.h"

#include <entity/entity.h>

#define PLAYER_WIDTH 32
#define PLAYER_HEIGHT 32

static void on_show(float screen_width, float screen_height)
{
    entity_t* player = entity_add((screen_width - PLAYER_WIDTH) / 2.0f, screen_height - PLAYER_HEIGHT * 1.5f, PLAYER_WIDTH, PLAYER_HEIGHT);
    {
        entity_component_add(player, render_component, (void*) &spritesheet.sprites.player_still);
        entity_component_add(player, controller_component, NULL);
    }
}

static bool on_update(float screen_width, float screen_height, float frame_time)
{
    if (IsKeyPressed(KEY_ESCAPE))
        return scene_show(&menu_scene);

    return false;
}

scene_t game_scene = {
    .on_show    = on_show,
    .on_update  = on_update,
    .on_hide    = NULL
};