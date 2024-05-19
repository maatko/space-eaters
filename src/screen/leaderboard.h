#ifndef SPACE_EATERS_LEADERBOARD_H
#define SPACE_EATERS_LEADERBOARD_H

#include "screen.h"

class LeaderBoard : public Screen {
protected:
    void OnShow() override;

    bool OnDraw(float sc_width, float sc_height, float frame_time) override;

    void OnHide() override;
};


#endif //SPACE_EATERS_LEADERBOARD_H
