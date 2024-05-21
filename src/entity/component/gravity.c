#include "component.h"

#include <entity/entity.h>

void gravity_component(entity_t* entity, void* component_data, float screen_width, float screen_height, float frame_time)
{
    entity->pos_y += (*(float*)component_data) * frame_time;

    if (entity->pos_y > screen_height - entity->height)
        entity->pos_y = 0;
}