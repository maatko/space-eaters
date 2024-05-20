#ifndef SPACE_EATERS_SCREEN_H
#define SPACE_EATERS_SCREEN_H

#include <unordered_map>
#include <vector>

#include <raylib.h>
#include <entity/entity.h>

class Screen {
public:
    enum ID {
        MENU,
        GAME,
        LEADERBOARD,

        NONE
    };
protected:
    virtual void OnShow(float sc_width, float sc_height) {
    }

    virtual bool OnDraw(float sc_width, float sc_height, float frame_time) {
        return false;
    };

    virtual void OnHide() {
    }

protected:
    void SpawnStars(float sc_width);

protected:
    std::vector<Entity *> m_Entities;

protected:
    static bool Button(const char *text, float x, float y, float width, float height, float font_size);

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
