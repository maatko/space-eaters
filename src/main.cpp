#include <cstdio>

#include <screen/screen.h>

int main() {
    // initialize the screen system before
    // the window is set up
    Screen::Initialize(Screen::ID::MENU);

    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE);
    InitWindow(640, 480, "Space Eaters");

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

    // clean up any memory that
    // has been taken by the screen system
    Screen::Clean();

    CloseWindow();
}