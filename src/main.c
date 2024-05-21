#include <raylib.h>

#include <scene/scene.h>
#include <sprite/spritesheet.h>

int main(void) {
    SetConfigFlags(FLAG_VSYNC_HINT);

    InitWindow(640, 480, "Space Eaters");
    {
        spritesheet_load("./assets/textures/spritesheet.png");

        scene_show(&menu_scene);
        {
            while (!WindowShouldClose())
            {
                BeginDrawing();
                {
                    ClearBackground(BLACK);
                    
                    if (scene_update(GetScreenWidth(), GetScreenHeight(), GetFrameTime()))
                        break;
                }
                EndDrawing();
            }
        }
        spritesheet_free();

        scene_free();
    }
    CloseWindow();
}
