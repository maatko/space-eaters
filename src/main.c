#include <raylib.h>

#include <scene/scene.h>
#include <sprite/spritesheet.h>
#include <entity/entity.h>

int main(void) {
    SetConfigFlags(FLAG_VSYNC_HINT);

    InitWindow(640, 480, "Space Eaters");
    {
        // make it so the `ESCAPE` key does
        // not exit the application
        SetExitKey(KEY_NULL);

        spritesheet_load("./assets/textures/spritesheet.png");

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
