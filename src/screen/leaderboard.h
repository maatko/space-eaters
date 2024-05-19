#ifndef SPACE_EATERS_LEADERBOARD_H
#define SPACE_EATERS_LEADERBOARD_H

#include "screen.h"

class LeaderBoard : public Screen {
protected:
    bool OnDraw(float sc_width, float sc_height, float frame_time) override;
};


#endif //SPACE_EATERS_LEADERBOARD_H
