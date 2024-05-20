#include "sprite/spritesheet.h"

#include <screen/screen.h>

int main() {
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(640, 480, "Space Eaters");

    // initialize the sprite sheet so
    // sprites can be rendered from it
    SpriteSheet::Initialize("./assets/images/spritesheet.png");

    // initialize the screen system
    // so the screens can be switched
    // (it starts on the menu screen)
    Screen::Initialize(Screen::ID::MENU);

    while (!WindowShouldClose()) {
        BeginDrawing();
        {
            ClearBackground(BLACK);

            if (Screen::Draw((float) GetScreenWidth(), (float) GetScreenHeight(), GetFrameTime())) {
                break;
            }
        }
        EndDrawing();
    }

    // clean up any memory taken
    // by the sprite sheet
    SpriteSheet::Clean();

    // clean up any memory that
    // has been taken by the screen system
    Screen::Clean();

    CloseWindow();
}