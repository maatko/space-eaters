#include "component.h"

#include <entity/entity.h>

#define MOVE_SPEED 150

void controller_component(entity_t* entity, void* component_data, float screen_width, float screen_height, float frame_time)
{
    if (IsKeyDown(KEY_UP))
        entity->pos_y -= MOVE_SPEED * frame_time;
    if (IsKeyDown(KEY_DOWN))
        entity->pos_y += MOVE_SPEED * frame_time;

    if (IsKeyDown(KEY_LEFT))
        entity->pos_x -= MOVE_SPEED * frame_time;
    if (IsKeyDown(KEY_RIGHT))
        entity->pos_x += MOVE_SPEED * frame_time;
}