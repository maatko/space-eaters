#include <cstdio>

#include <spritesheet.h>
#include <screen/screen.h>

int main() {
    // initialize the screen system before
    // the window is set up
    Screen::Initialize(Screen::ID::MENU);

    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);

    InitWindow(640, 480, "Space Eaters");

    // initialize the sprite sheet so
    // sprites can be rendered from it
    SpriteSheet::Initialize("./assets/images/spritesheet.png");

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