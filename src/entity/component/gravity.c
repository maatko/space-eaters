#include "component.h"

#include <entity/entity.h>

#define GRAVITY_SPEED 100

void gravity_component(entity_t* entity, void* component_data, float screen_width, float screen_height, float frame_time)
{
    entity->pos_y -= GRAVITY_SPEED * frame_time;

    if (entity->pos_y + entity->height < 0)
        entity_delete(entity);
}