#include "component.h"

#include <stddef.h>

#include <sprite/spritesheet.h>
#include <entity/entity.h>

void render_component(entity_t* entity, void* component_data, float screen_width, float screen_height, float frame_time)
{
    const sprite_t* sprite = (const sprite_t*) component_data;
    if (sprite == NULL)
        return;
    
    spritesheet_draw(sprite, entity->pos_x, entity->pos_y, entity->width, entity->height, 0);
}