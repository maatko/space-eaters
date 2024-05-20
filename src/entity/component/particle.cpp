//
// Created by mat on 5/20/2024.
//

#include "particle.h"

ParticleComponent::ParticleComponent(const Sprite *sprite) {
    m_Sprite = sprite;
}

void ParticleComponent::OnUpdate(float sc_width, float sc_height, float frame_time) {
    m_Sprite->Draw(
            *m_EntityPositionX, *m_EntityPositionY,
            *m_EntityWidth, *m_EntityHeight,
            0
    );
}
