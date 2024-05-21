#include "component.h"

#include <assert.h>
#include <entity/entity.h>

void confetti_component(entity_t* entity, void* component_data, float screen_width, float screen_height, float frame_time)
{
    confetti_t* confetti = (confetti_t*)component_data;
    assert(confetti != NULL);

    if (confetti->flip)
    {
        if (confetti->scale > 0)
        {
            confetti->scale -= confetti->speed * frame_time;
        }
        else
        {
            free(confetti);
            entity_delete(entity);
        }

        entity->pos_x -= -confetti->scale / 2.0f;
        entity->pos_y -= -confetti->scale / 2.0f;

        entity->width += -confetti->scale;
        entity->height += -confetti->scale;

        return;
    }

    if (confetti->scale < confetti->max_scale)    
        confetti->scale += 0.05f * frame_time;
    else
        confetti->flip = true;

    entity->pos_x -= confetti->scale / 2.0f;
    entity->pos_y -= confetti->scale / 2.0f;

    entity->width += confetti->scale;
    entity->height += confetti->scale;
}