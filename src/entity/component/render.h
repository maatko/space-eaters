#ifndef SPACE_EATERS_RENDER_H
#define SPACE_EATERS_RENDER_H

#include "component.h"

#include <sprite/sprite.h>

class RenderComponent : public Component {
public:
    RenderComponent(const Sprite *left, const Sprite *right, const Sprite *still);

protected:
    void OnUpdate(float sc_width, float sc_height, float frame_time) override;

private:
    const Sprite *m_LeftSprite;
    const Sprite *m_RightSprite;
    const Sprite *m_StillSprite;
};

#endif //SPACE_EATERS_RENDER_H
