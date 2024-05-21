#include "component.h"

#include <entity/entity.h>

#define MOVE_SPEED 150

void controller_component(entity_t* entity, void* component_data, float screen_width, float screen_height, float frame_time)
{
    float movement_speed = MOVE_SPEED * frame_time;
    {
        if (IsKeyDown(KEY_UP))
            entity->pos_y -= movement_speed;
        if (IsKeyDown(KEY_DOWN))
            entity->pos_y += movement_speed;

        if (IsKeyDown(KEY_LEFT))
            entity->pos_x -= movement_speed;
        if (IsKeyDown(KEY_RIGHT))
            entity->pos_x += movement_speed;
    }

    if (IsKeyPressed(KEY_SPACE))
    {
        static const bullet_width = 8;
        static const bullet_height = 8;

        entity_t* bullet = entity_add(entity->pos_x + (entity->width - bullet_width) / 2.0f, entity->pos_y, bullet_width, bullet_height);
        {
            entity_component_add(bullet, render_component, (void*)&spritesheet.sprites.bullet);
            entity_component_add(bullet, gravity_component, NULL);
        }
    }
}