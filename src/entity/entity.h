#ifndef ENTITY_D
#define ENTITY_D

#include <stdint.h>
#include <stdbool.h>

#include <sprite/spritesheet.h>

#include "component/component.h"

typedef struct entity_t
{
    component_t components[MAX_COMPONENT_SIZE];
    int component_count;

    float pos_x;
    float pos_y;

    float width;
    float height;

    bool enemy;

    // any data that needs to be
    // tracked between components
    void* data;

    // location where to entity is
    // located in the linked list
    struct entity_t* previous;
    struct entity_t* next;
} entity_t;

entity_t* entity_list();

entity_t* entity_add(float x, float y, float width, float height);

component_t* entity_component_add(entity_t* entity, on_component_update component_update, void* data);

void entity_update(float screen_width, float screen_height, float frame_time);

void entity_delete(entity_t* entity);

void entity_free();

#endif //ENTITY_D