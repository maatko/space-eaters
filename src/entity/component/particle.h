//
// Created by mat on 5/20/2024.
//

#ifndef SPACE_EATERS_PARTICLE_H
#define SPACE_EATERS_PARTICLE_H

#include "component.h"

#include <sprite/sprite.h>

class ParticleComponent : public Component {
public:
    ParticleComponent(const Sprite *sprite);

protected:
    void OnUpdate(float sc_width, float sc_height, float frame_time) override;

private:
    const Sprite *m_Sprite;
};

#endif //SPACE_EATERS_PARTICLE_H
