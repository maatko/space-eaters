//
// Created by mat on 5/19/2024.
//

#include "game.h"

#include "sprite/spritesheet.h"
#include <cstdio>

#include <entity/entity.h>
#include <entity/component/controller.h>
#include <entity/component/render.h>

static const float FRAME_PADDING = 0.01f;
static const float FRAME_HEIGHT = 0.2f;
static const float FRAME_HALF_WIDTH = 0.2f;
static const float FRAME_FULL_WIDTH = 1.0f - (FRAME_HALF_WIDTH * 2 + FRAME_PADDING);
static const float FRAME_ICON_SIZE = 24;
static const int FRAME_FONT_SIZE = 20;

struct {
    Entity *player;

    float score;
    float multiplier;

    int hearts;
    int bombs;
} Game;

static void DrawHUD(float sc_width, float sc_height) {
    char text_display[1024];

    float x_pos = 0;
    float y_pos = 0;

    // left side of the HUD
    {
        Sprite::FRAME_LEFT->Draw(
                x_pos, y_pos,
                sc_width * FRAME_HALF_WIDTH, sc_height * FRAME_HEIGHT,
                0
        );

        float x_offset = x_pos + ((sc_width * FRAME_HALF_WIDTH - FRAME_ICON_SIZE) / 2.0f);
        {
            Sprite::HEART->Draw(
                    x_offset - 5,
                    (y_pos + (sc_height * FRAME_HEIGHT - FRAME_ICON_SIZE) / 2.0f),
                    FRAME_ICON_SIZE, FRAME_ICON_SIZE,
                    0
            );
        }
        x_offset += FRAME_ICON_SIZE;

        // append the score to the text display buffer
        sprintf(text_display, "%d", (int) Game.hearts);

        DrawText(
                text_display,
                (int) x_offset + 8,
                (int) (y_pos + (sc_height * FRAME_HEIGHT - FRAME_FONT_SIZE) / 2.0f),
                FRAME_FONT_SIZE,
                GREEN
        );
    }
    x_pos += sc_width * FRAME_HALF_WIDTH + sc_width * FRAME_PADDING;

    // middle of the HUD
    {
        Sprite::FRAME_FULL->Draw(
                x_pos, y_pos,
                sc_width * FRAME_FULL_WIDTH, sc_height * FRAME_HEIGHT,
                0
        );

        // append the score to the text display buffer
        sprintf(text_display, "%d", (int) Game.score);

        DrawText(
                text_display,
                (int) ((sc_width - (float) MeasureText(text_display, FRAME_FONT_SIZE)) / 2.0f),
                (int) ((sc_height * FRAME_HEIGHT - FRAME_FONT_SIZE) / 2.0f),
                FRAME_FONT_SIZE,
                GREEN
        );
    }
    x_pos += sc_width * FRAME_FULL_WIDTH + sc_width * FRAME_PADDING;

    // right side of the HUD
    {
        Sprite::FRAME_RIGHT->Draw(
                x_pos, y_pos,
                sc_width * FRAME_HALF_WIDTH, sc_height * FRAME_HEIGHT,
                0
        );

        float x_offset = x_pos + (sc_width * FRAME_HALF_WIDTH - FRAME_ICON_SIZE) / 2.0f;
        {
            Sprite::BOMB->Draw(
                    x_offset - FRAME_ICON_SIZE + 5,
                    y_pos + (sc_height * FRAME_HEIGHT - FRAME_ICON_SIZE) / 2.0f,
                    FRAME_ICON_SIZE, FRAME_ICON_SIZE,
                    0
            );
        }
        x_offset += FRAME_ICON_SIZE;

        // append the bomb count to the text display buffer
        sprintf(text_display, "%d", (int) Game.bombs);

        DrawText(
                text_display,
                (int) x_offset - 5,
                (int) (y_pos + (sc_height * FRAME_HEIGHT - FRAME_FONT_SIZE) / 2.0f),
                FRAME_FONT_SIZE,
                GREEN
        );
    }
}

void GameScreen::OnShow(float sc_width, float sc_height) {
    Game.score = 0.0f;
    Game.hearts = 1;
    Game.multiplier = 1.0f;

    SpawnStars(sc_width);

    Game.player = new Entity((sc_width - 32) / 2.0f, sc_height - 32 * 2, 32, 32);

    AddEntity(Game.player);

    {
        Game.player->AddComponent(new ControllerComponent(150.0f));
        Game.player->AddComponent(new RenderComponent(
                Sprite::PLAYER_LEFT,
                Sprite::PLAYER_RIGHT,
                Sprite::PLAYER_STILL
        ));
    }
}

bool GameScreen::OnDraw(float sc_width, float sc_height, float frame_time) {
    Game.score += 1 * Game.multiplier * frame_time;
    Game.multiplier += 0.15f * frame_time;

    DrawHUD(sc_width, sc_height);

    return false;
}

void GameScreen::OnHide() {
    delete Game.player;
}