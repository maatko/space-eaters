//
// Created by mat on 5/19/2024.
//

#include "menu.h"

#include <cmath>

#include "sprite/spritesheet.h"

static constexpr float PADDING = 15;

static constexpr float BANNER_WIDTH = 30 * 5;
static constexpr float BANNER_HEIGHT = 23 * 5;

static constexpr float SPLASH_WIDTH = 47 * 1.5f;
static constexpr float SPLASH_HEIGHT = 23 * 1.5f;

static constexpr float BUTTON_WIDTH = 200;
static constexpr float BUTTON_HEIGHT = 50;
static constexpr float BUTTON_TEXT_SIZE = 15;

bool MenuScreen::OnDraw(float sc_width, float sc_height, float frame_time) {
    float pos_x = (sc_width - BUTTON_WIDTH) / 2.0f;
    float pos_y = (sc_height - (BUTTON_HEIGHT + PADDING) * 3 + (BANNER_HEIGHT + PADDING * 3)) / 2.0f;

    Sprite::BOSS->Draw(
            (sc_width - BANNER_WIDTH) / 2.0f, pos_y - (BANNER_HEIGHT + PADDING * 3),
            BANNER_WIDTH, BANNER_HEIGHT,
            0
    );

    float animation = (1.8f - (float) abs(sin((GetTime() * PI * 2.0) * 0.1))) * 100.0F / (float) (SPLASH_WIDTH + 32);
    {
        Sprite::LOGO->Draw(
                (sc_width - BANNER_WIDTH) / 2.0f + BANNER_WIDTH - SPLASH_WIDTH / 2.0f,
                pos_y - (BANNER_HEIGHT + PADDING * 3) + BANNER_HEIGHT / 2.0f + SPLASH_HEIGHT,
                SPLASH_WIDTH * animation, SPLASH_HEIGHT * animation,
                -25
        );
    }

    if (Button("Play", pos_x, pos_y, BUTTON_WIDTH, BUTTON_HEIGHT, BUTTON_TEXT_SIZE)) {
        Screen::Show(Screen::ID::GAME);
        return false;
    }
    pos_y += BUTTON_HEIGHT + PADDING;

    if (Button("Leaderboard", pos_x, pos_y, BUTTON_WIDTH, BUTTON_HEIGHT, BUTTON_TEXT_SIZE)) {
        Screen::Show(Screen::ID::LEADERBOARD);
        return false;
    }
    pos_y += BUTTON_HEIGHT + PADDING;

    return Button("Quit", pos_x, pos_y, BUTTON_WIDTH, BUTTON_HEIGHT, BUTTON_TEXT_SIZE);
}

void MenuScreen::OnShow(float sc_width, float sc_height) {
    SpawnStars(sc_width);
}
