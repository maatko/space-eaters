#ifndef ENTITY_COMPONENT_D
#define ENTITY_COMPONENT_D

#define MAX_COMPONENT_SIZE 256

struct entity_t;
typedef void (*on_component_update)(struct entity_t* entity, void* component_data, float screen_width, float screen_height, float frame_time);

typedef struct component_t
{
    void* data;
    on_component_update on_update;
} component_t;

extern void render_sprite_component(struct entity_t* entity, void* component_data, float screen_width, float screen_height, float frame_time);
extern void controller_component(struct entity_t* entity, void* component_data, float screen_width, float screen_height, float frame_time);

#endif //ENTITY_COMPONENT_D