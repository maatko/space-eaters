#include "component.h"

#include <stddef.h>

#include <data.h>
#include <entity/entity.h>

#define PADDING 5

void collision_component(entity_t* entity, void* component_data, float screen_width, float screen_height, float frame_time)
{
    entity_t* it = entity_list();
    while(it != NULL)
    {
        if (it != entity)
        {
            Rectangle bullet = { entity->pos_x - PADDING, entity->pos_y - PADDING, entity->width + PADDING, entity->height + PADDING };
            Rectangle target = { it->pos_x - PADDING, it->pos_y - PADDING, it->width + PADDING, it->height + PADDING };

            if (CheckCollisionRecs(target, bullet))
            {
                if (data.on_collide != NULL)
                    data.on_collide(entity, it);
            }
        }
        it = it->next;
    }
}