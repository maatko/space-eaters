#ifndef SPACE_EATERS_GAME_H
#define SPACE_EATERS_GAME_H

#include "screen.h"

class GameScreen : public Screen {
protected:
    void OnShow(float sc_width, float sc_height) override;

    bool OnDraw(float sc_width, float sc_height, float frame_time) override;

    void OnHide() override;
};

#endif //SPACE_EATERS_GAME_H
