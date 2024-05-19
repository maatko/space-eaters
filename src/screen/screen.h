//
// Created by mat on 5/19/2024.
//

#ifndef SPACE_EATERS_SCREEN_H
#define SPACE_EATERS_SCREEN_H

#include <unordered_map>

#include <raylib.h>

class Screen {
public:
    enum ID {
        MENU,
        GAME,

        NONE
    };
protected:
    virtual void OnShow() {
    }

    virtual bool OnDraw(float sc_width, float sc_height, float frame_time) {
        return false;
    };

    virtual void OnHide() {
    }

public:
    static void Initialize(ID screen_id);

    static void Show(ID screen_id);

    static bool Draw(float sc_width, float sc_height, float frame_time);

    static void Clean();

private:
    static std::unordered_map<ID, Screen *> m_ScreenMap;
    static ID m_CurrentScreen;
};

#endif //SPACE_EATERS_SCREEN_H