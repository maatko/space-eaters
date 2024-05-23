#include "entity.h"

#include <stdlib.h>
#include <assert.h>

static entity_t* entities = NULL;

entity_t* entity_list()
{
    return entities;
}

entity_t* entity_add(float x, float y, float width, float height)
{
    entity_t* entity = (entity_t*)malloc(sizeof(entity_t));
    assert(entity != NULL);

    {
        entity->component_count = 0;
        entity->data = NULL;

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
            entity->previous = it;
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

component_t* entity_component_get(entity_t* entity, void* component)
{
    for(int i = 0; i < entity->component_count; i++)
    {
        component_t* component_ptr = &entity->components[i];
        if (component_ptr->on_update == component)
            return component_ptr;
    }
    return NULL;
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
    if (entity == NULL)
        return;

    if (entities == entity)
        entities = entity->next;
    
    if (entity->next != NULL)
        entity->next->previous = entity->previous;
    if (entity->previous != NULL)
        entity->previous->next = entity->next;

    entity->component_count = 0;

    if (entity->data != NULL)
        free(entity->data);
    
    free(entity);
    entity = NULL;
}

void entity_free()
{
    entity_t* it = entities;
    {
        while(it != NULL)
        {
            entity_t* temp = it;
            it = it->next;

            temp->component_count = 0;

            if (temp->data != NULL)
                free(temp->data);

            free(temp);
        }
    }
    entities = NULL;
}