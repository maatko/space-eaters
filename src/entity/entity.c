#include "entity.h"

#include <stdlib.h>
#include <assert.h>

static entity_t* entities = NULL;

entity_t* entity_add(float x, float y, float width, float height)
{
    entity_t* entity = (entity_t*)malloc(sizeof(entity_t));
    assert(entity != NULL);

    {
        entity->component_count = 0;

        entity->pos_x = x;
        entity->pos_y = y;
        
        entity->width = width;
        entity->height = height;

        entity->next = NULL;
        entity->previous = NULL;  
    }

    if (entities == NULL)
    {
        entities = entity;
        return entity;
    }

    entity_t* it = entities;
    while(it != NULL)
    {
        if (it->next == NULL)
        {
            it->next = entity;
            entity->previous = it->next;
            break;
        }

        it = it->next;
    }

    return entity;
}

component_t* entity_component_add(entity_t* entity, on_component_update component_update, void* data)
{
    int index = entity->component_count + 1;
    if (index > MAX_COMPONENT_SIZE)
        return NULL;
    
    entity->component_count = index;

    component_t* component = &entity->components[index - 1];
    {
        component->data = data;
        component->on_update = component_update;
    }
    
    return component;
}

void entity_update(float screen_width, float screen_height, float frame_time)
{
    entity_t* it = entities;
    while(it != NULL)
    {
        for(int i = 0; i < it->component_count; i++)
        {
            component_t component = it->components[i];
            component.on_update(it, component.data, screen_width, screen_height, frame_time);
        }

        it = it->next;
    }
}

void entity_delete(entity_t* entity)
{
    // TODO :: implement method
}

void entity_free()
{
    entity_t* it = entities;
    while(it != NULL)
    {
        entity_t* temp = it;
        it = temp->next;
        free(temp);
    }
}