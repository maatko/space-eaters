#include "component.h"

#include <stddef.h>

#include <data.h>
#include <entity/entity.h>

static const float bullet_speed = -250.0f;

void controller_component(entity_t* entity, void* component_data, float screen_width, float screen_height, float frame_time)
{
    float movement_speed = (*(float*)component_data) * frame_time;
    {
        if (IsKeyDown(KEY_LEFT))
            entity->pos_x -= movement_speed;
        if (IsKeyDown(KEY_RIGHT))
            entity->pos_x += movement_speed;

        if (entity->pos_x < 0)
            entity->pos_x = 0;
        if (entity->pos_x + entity->width >= screen_width)
            entity->pos_x = screen_width - entity->width;
    }

    if (IsKeyPressed(KEY_UP))
    {
        const sprite_t* bullet_sprite = &spritesheet.sprites.bullet;
        {
            const float bullet_width = bullet_sprite->width * 2;
            const float bullet_height = bullet_sprite->height * 2;

            entity_t* bullet = entity_add(entity->pos_x + (entity->width - bullet_width) / 2.0f, entity->pos_y, bullet_width, bullet_height);
            {
                entity_component_add(bullet, render_component, (void*)bullet_sprite);
                entity_component_add(bullet, gravity_component, (void*)&bullet_speed);
                entity_component_add(bullet, collision_component, NULL);
            }
        }
    }

    if (IsKeyPressed(KEY_SPACE))
    {
        if (data.bombs < 1)
            return;
        
        entity_t* it = entity_list();
        while(it != NULL)
        {
            component_t* sprite_component = (component_t*) entity_component_get(it, render_component);
            if (sprite_component == NULL)
                continue;

            const sprite_t* sprite = (const sprite_t*) sprite_component->data;
            if (sprite == NULL)
                continue;

            if (sprite == &spritesheet.sprites.enemy_yellow)
            {
                entity_delete(it);
                data.score += 100;
                data.bombs--;
            }

            it = it->next;
        }
    }
}