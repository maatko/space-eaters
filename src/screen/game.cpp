//
// Created by mat on 5/19/2024.
//

#include "game.h"

#include <entity/entity.h>
#include <entity/component/sprite.h>
#include <entity/component/controller.h>

static Entity *entity;

bool GameScreen::OnDraw(float sc_width, float sc_height, float frame_time) {
    if (entity == nullptr) {
        return false;
    }

    entity->OnUpdate(sc_width, sc_height, frame_time);

    return false;
}

void GameScreen::OnHide() {
    delete entity;
}

void GameScreen::OnShow() {
    entity = new Entity(100, 100, 32, 32);
    {
        entity->AddComponent(new ControllerComponent(150.0f));
        entity->AddComponent(new SpriteComponent(0, 1, 8, 7));
    }
}
