#include <stdio.h>

#define RAYGUI_IMPLEMENTATION

#include <raylib.h>
#include <raygui.h>

const int screen_width = 640;
const int screen_height = 480;

int main(void) {
    SetConfigFlags(FLAG_VSYNC_HINT);

    InitWindow(screen_width, screen_height, "Space Invaders");

    Texture2D texture = LoadTexture("./assets/images/background.png");

    float offset = 0;
    while (!WindowShouldClose()) {
        offset += 25.0f * GetFrameTime();

        BeginDrawing();
        {
            ClearBackground(RAYWHITE);
            DrawTextureEx(texture, (Vector2) {0, offset}, 0.0f, 1.0f, WHITE);
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}