#ifndef SPACE_EATERS_MENU_H
#define SPACE_EATERS_MENU_H

#include "screen.h"

class MenuScreen : public Screen {
protected:
    void OnShow(float sc_width, float sc_height) override;

    bool OnDraw(float sc_width, float sc_height, float frame_time) override;
};

#endif //SPACE_EATERS_MENU_H
