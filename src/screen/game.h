//
// Created by mat on 5/19/2024.
//

#ifndef SPACE_EATERS_GAME_H
#define SPACE_EATERS_GAME_H

#include "screen.h"

class GameScreen : public Screen {
protected:
    void OnShow() override;

    bool OnDraw(float sc_width, float sc_height, float frame_time) override;

    void OnHide() override;
};

#endif //SPACE_EATERS_GAME_H
