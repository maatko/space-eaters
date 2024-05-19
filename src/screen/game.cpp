//
// Created by mat on 5/19/2024.
//

#include "game.h"

#include <spritesheet.h>

#include <entity/entity.h>
#include <entity/component/sprite.h>
#include <entity/component/controller.h>

struct {
    Entity *player;
    float score;
    float multiplier;
    int hearts;
} game;

static void draw_hearts_display(float sc_width, float sc_height) {
    SpriteSheet::Get()->DrawSprite(
            0, 0,
            1, 106,
            sc_width * 0.2f, sc_height * 0.2f,
            31, 22,
            0
    );

    SpriteSheet::Get()->DrawSprite(
            (sc_width * 0.2f - 54) / 2.0f, (sc_height * 0.2f - 25) / 2.0f,
            51, 20,
            25, 25,
            8, 7,
            0
    );

    char hearts_display[1024];
    sprintf(hearts_display, "%d", (int) game.hearts);

    DrawText(
            hearts_display,
            (int) ((sc_width * 0.2f - (float) MeasureText(hearts_display, 20)) / 2.0f + 15),
            (int) ((sc_height * 0.2f - 16) / 2.0f) - 1,
            20,
            WHITE
    );

}

static void draw_score_display(float sc_width, float sc_height) {
    SpriteSheet::Get()->DrawSprite(
            sc_width * 0.21f, 0,
            32, 106,
            sc_width * 0.58f, sc_height * 0.2f,
            64, 22,
            0
    );

    char score_display[1024];
    sprintf(score_display, "%d", (int) game.score);

    DrawText(
            score_display,
            (int) ((sc_width - (float) MeasureText(score_display, 25)) / 2.0f),
            (int) ((sc_height * 0.2f - 25) / 2.0f),
            25,
            GREEN
    );
}

void GameScreen::OnShow(float sc_width, float sc_height) {
    game.score = 0.0f;
    game.hearts = 1;
    game.multiplier = 1.0f;

    game.player = new Entity((sc_width - 32) / 2.0f, sc_height - 32 * 2, 32, 32);
    {
        game.player->AddComponent(new ControllerComponent(150.0f));
        game.player->AddComponent(new SpriteComponent(
                {0, 0, 0, 0, 0},
                {9, 1, 7, 7, 0},
                {0, 0, 0, 0, 0},
                {0, 34, 8, 7, 0},
                {0, 1, 8, 7, 0}
        ));
    }
}

bool GameScreen::OnDraw(float sc_width, float sc_height, float frame_time) {
    game.score += 1 * game.multiplier * frame_time;
    game.multiplier += 0.15f * frame_time;

    draw_hearts_display(sc_width, sc_height);
    draw_score_display(sc_width, sc_height);

    SpriteSheet::Get()->DrawSprite(
            sc_width - sc_width * 0.2f, 0,
            96, 106,
            sc_width * 0.2f, sc_height * 0.2f,
            31, 22,
            0
    );

    game.player->OnUpdate(sc_width, sc_height, frame_time);

    return false;
}

void GameScreen::OnHide() {
    delete game.player;
}