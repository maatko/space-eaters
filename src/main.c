#include <raylib.h>

#include <scene/scene.h>
#include <sprite/spritesheet.h>
#include <entity/entity.h>

int main(void) {
    SetConfigFlags(FLAG_VSYNC_HINT);

    InitWindow(640, 480, "Space Eaters");
    {
        spritesheet_load("./assets/textures/spritesheet.png");

        entity_t* player = entity_add(100, 100, 32, 32);
        entity_component_add(player, render_component, (void*)&spritesheet.sprites.player_still);
        entity_component_add(player, controller_component, NULL);

        scene_show(&menu_scene);
        {
            while (!WindowShouldClose())
            {
                BeginDrawing();
                {
                    ClearBackground(BLACK);

                    float screen_width = (float) GetScreenWidth();
                    float screen_height = (float) GetScreenHeight();
                    float frame_time = GetFrameTime();

                    entity_update(screen_width, screen_height, frame_time);
                    
                    if (scene_update(screen_width, screen_height, frame_time))
                        break;
                }
                EndDrawing();
            }
        }

        spritesheet_free();
        entity_free();
        scene_free();
    }
    CloseWindow();
}
