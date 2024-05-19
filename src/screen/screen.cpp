//
// Created by mat on 5/19/2024.
//

#include "screen.h"

#include "menu.h"
#include "game.h"

std::unordered_map<Screen::ID, Screen *> Screen::m_ScreenMap;
Screen::ID Screen::m_CurrentScreen = Screen::ID::NONE;

bool Screen::Draw(float sc_width, float sc_height, float frame_time) {
    return m_ScreenMap[m_CurrentScreen]->OnDraw(sc_width, sc_height, frame_time);
}

void Screen::Initialize(const Screen::ID screen_id) {
    m_ScreenMap.insert({Screen::ID::MENU, new MenuScreen()});
    m_ScreenMap.insert({Screen::ID::GAME, new GameScreen()});

    Show(screen_id);
}

void Screen::Show(Screen::ID screen_id) {
    if (m_CurrentScreen != Screen::ID::NONE) {
        m_ScreenMap[m_CurrentScreen]->OnHide();
    }

    m_CurrentScreen = screen_id;

    if (m_CurrentScreen != Screen::ID::NONE) {
        m_ScreenMap[m_CurrentScreen]->OnShow();
    }
}

void Screen::Clean() {
    printf("INFO: Freeing memory taken by the Screen system");

    for (const auto &item: m_ScreenMap) {
        delete item.second;
    }
}
