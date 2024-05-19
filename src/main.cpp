#include <cstdio>

#define RAYGUI_IMPLEMENTATION

#include <raylib.h>

#include <spritesheet.h>

int main() {
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);

    InitWindow(640, 480, "Space Eaters");

    SpriteSheet sprite_sheet("./assets/images/spritesheet.png");

    float offset = 0;
    while (!WindowShouldClose()) {
        offset += 25.0f * GetFrameTime();

        BeginDrawing();
        {
            ClearBackground(BLACK);

            sprite_sheet.DrawSprite(
                    250, 250,
                    0, 1,
                    8 * 5, 7 * 5,
                    8, 7,
                    offset
            );

            offset += 25.0f * GetFrameTime();
        }
        EndDrawing();
    }

    CloseWindow();
}