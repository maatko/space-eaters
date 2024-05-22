#ifndef SCENE_H
#define SCENE_H

#include <stdbool.h>
#include <raylib.h>

#include <sprite/spritesheet.h>

typedef void (*on_show_t)(float screen_width, float screen_height);
typedef bool (*on_update_t)(float screen_width, float screen_height, float frame_time);
typedef void (*on_hide_t)();

typedef struct {
    on_show_t on_show;
    on_update_t on_update;
    on_hide_t on_hide;
} scene_t;

bool scene_show(scene_t* scene);
bool scene_update(float screen_width, float screen_height, float frame_time);
bool scene_button(const char* text, float x, float y, float width, float height, int font_size);
void scene_free();

extern scene_t menu_scene;
extern scene_t game_scene;
extern scene_t over_scene;

#endif //SCENE_H
