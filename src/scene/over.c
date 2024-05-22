#include "scene.h"

#include <stdio.h>
#include <data.h>

static bool on_update(float screen_width, float screen_height, float frame_time)
{
    if (IsKeyPressed(KEY_ENTER))
        return scene_show(&game_scene);

    char text[1024];
    {
        sprintf(text, "Game Over!");
        DrawText(text, (screen_width - MeasureText(text, 50)) / 2.0f, 150, 50, WHITE);

        sprintf(text, "%d", (int)data.score);
        DrawText(text, (screen_width - MeasureText(text, 35)) / 2.0f, 150 + 75, 35, WHITE);

        sprintf(text, "Press `ENTER` to continue!");
        DrawText(text, (screen_width - MeasureText(text, 35)) / 2.0f, 150 + 75 + 65, 35, WHITE);
    }

    return false;
}

scene_t over_scene = {
    .on_show    = NULL,
    .on_update  = on_update,
    .on_hide    = NULL
};