#include "component.h"

#include <assert.h>

#include <data.h>
#include <entity/entity.h>

void gravity_component(entity_t* entity, void* component_data, float screen_width, float screen_height, float frame_time)
{
    entity->pos_y += (*(float*)component_data) * frame_time;

    if (entity->pos_y > screen_height - entity->height)
    {
        component_t* sprite_renderer = entity_component_get(entity, render_component);
        assert(sprite_renderer != NULL);

        const sprite_t* sprite = (const sprite_t*) sprite_renderer->data;
        if (sprite == &spritesheet.sprites.star)
        {
            entity->pos_y = 0;
        }
        else
        {
            data.hearts--;
            entity_delete(entity);
        }
    }
}