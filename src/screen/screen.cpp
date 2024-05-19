//
// Created by mat on 5/19/2024.
//

#include "screen.h"

#include "menu.h"
#include "game.h"
#include "leaderboard.h"

#include <spritesheet.h>

std::unordered_map<Screen::ID, Screen *> Screen::m_ScreenMap;
Screen::ID Screen::m_CurrentScreen = Screen::ID::NONE;

bool Screen::Button(const char *text, float x, float y, float width, float height, float font_size) {
    SpriteSheet::Get()->DrawSprite(x, y, 32, 106, width, height, 64, 22, 0);

    bool hovered = CheckCollisionPointRec(GetMousePosition(), {x, y, width, height});

    DrawText(
            text,
            (int) (x + (width - (float) MeasureText(text, (int) font_size)) / 2.0f),
            (int) (y + (height - font_size) / 2.0f), (int) font_size,
            hovered ? GREEN : WHITE
    );

    return IsMouseButtonDown(MOUSE_BUTTON_LEFT) && hovered;
}

bool Screen::Draw(float sc_width, float sc_height, float frame_time) {
    return m_ScreenMap[m_CurrentScreen]->OnDraw(sc_width, sc_height, frame_time);
}

void Screen::Initialize(const Screen::ID screen_id) {
    m_ScreenMap.insert({Screen::ID::MENU, new MenuScreen()});
    m_ScreenMap.insert({Screen::ID::GAME, new GameScreen()});
    m_ScreenMap.insert({Screen::ID::LEADERBOARD, new LeaderBoard()});

    Show(screen_id);
}

void Screen::Show(Screen::ID screen_id) {
    if (m_CurrentScreen != Screen::ID::NONE) {
        m_ScreenMap[m_CurrentScreen]->OnHide();
    }

    m_CurrentScreen = screen_id;

    if (m_CurrentScreen != Screen::ID::NONE) {
        m_ScreenMap[m_CurrentScreen]->OnShow((float) GetScreenWidth(), (float) GetScreenHeight());
    }
}

void Screen::Clean() {
    printf("INFO: Freeing memory taken by the Screen system");

    for (const auto &item: m_ScreenMap) {
        item.second->OnHide();

        delete item.second;
    }
}

