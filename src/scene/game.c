#include "scene.h"

#include <entity/entity.h>

static void on_show(float screen_width, float screen_height)
{
    entity_t* player = entity_add(100, 100, 32, 32);
    entity_component_add(player, render_component, &spritesheet.sprites.player_still);
    entity_component_add(player, controller_component, NULL);
}

static bool on_update(float screen_width, float screen_height, float frame_time)
{
    return false;
}

scene_t game_scene = {
    .on_show    = on_show,
    .on_update  = on_update,
    .on_hide    = NULL
};