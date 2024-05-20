//
// Created by mat on 5/19/2024.
//

#include "screen.h"

#include "menu.h"
#include "game.h"
#include "leaderboard.h"
#include "sprite/spritesheet.h"

#include <cstdio>
#include <ctime>
#include <algorithm>

#include <entity/component/gravity.h>
#include <entity/component/particle.h>

std::unordered_map<Screen::ID, Screen *> Screen::m_ScreenMap;
Screen::ID Screen::m_CurrentScreen = Screen::ID::NONE;

void Screen::AddEntity(Entity *entity) {
    entity->m_Screen = this;

    m_Entities.push_back(entity);
}

void Screen::RemoveEntity(Entity *entity) {
    m_Entities.erase(std::remove(m_Entities.begin(), m_Entities.end(), entity), m_Entities.end());
    delete entity;
}

void Screen::SpawnStars(float sc_width) {
    srand(time(nullptr));

    for (int i = 0; i < (int) (sc_width / 3.0f); i++) {
        auto *star_entity = new Entity(i * 5, 0, 3, 3);

        AddEntity(star_entity);
        {
            star_entity->AddComponent(new GravityComponent((rand() / (float) RAND_MAX) * 150, true));
            star_entity->AddComponent(new ParticleComponent(Sprite::STAR));
        }
    }
}

bool Screen::Button(const char *text, float x, float y, float width, float height, float font_size) {
    Sprite::FRAME_FULL->Draw(x, y, width, height, 0);

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
    auto screen = m_ScreenMap[m_CurrentScreen];
    for (const auto entity: screen->m_Entities) {
        entity->OnUpdate(sc_width, sc_height, frame_time);
    }

    return screen->OnDraw(sc_width, sc_height, frame_time);
}

void Screen::Initialize(const Screen::ID screen_id) {
    m_ScreenMap.insert({Screen::ID::MENU, new MenuScreen()});
    m_ScreenMap.insert({Screen::ID::GAME, new GameScreen()});
    m_ScreenMap.insert({Screen::ID::LEADERBOARD, new LeaderBoard()});

    Show(screen_id);
}

void Screen::Show(Screen::ID screen_id) {
    if (m_CurrentScreen != Screen::ID::NONE) {
        auto screen = m_ScreenMap[m_CurrentScreen];

        // make sure to clear all the entities
        // for each screen that is closed
        for (const auto entity: screen->m_Entities) {
            delete entity;
        }
        screen->m_Entities.clear();

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

