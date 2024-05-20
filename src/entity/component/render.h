//
// Created by mat on 5/20/2024.
//

#ifndef SPACE_EATERS_RENDER_H
#define SPACE_EATERS_RENDER_H

#include "component.h"

class RenderComponent : public Component {
public:
    void OnUpdate(float sc_width, float sc_height, float frame_time) override;
};


#endif //SPACE_EATERS_RENDER_H
