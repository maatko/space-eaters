//
// Created by mat on 5/19/2024.
//

#include "menu.h"

#include <raygui.h>

bool MenuScreen::OnDraw(float sc_width, float sc_height, float frame_time) {
    if (GuiButton({100, 100, 100, 50}, "Game")) {
        Screen::Show(Screen::ID::GAME);
        return false;
    }

    if (GuiButton({100, 200, 100, 50}, "Quit")) {
        return true;
    }

    return false;
}

void MenuScreen::OnHide() {
}

void MenuScreen::OnShow() {
}
