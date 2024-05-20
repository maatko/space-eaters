//
// Created by mat on 5/20/2024.
//

#include "render.h"

#include <entity/entity.h>
#include <entity/component/controller.h>

RenderComponent::RenderComponent(const Sprite *left, const Sprite *right, const Sprite *still) {
    m_LeftSprite = left;
    m_RightSprite = right;
    m_StillSprite = still;
}

void RenderComponent::OnUpdate(float sc_width, float sc_height, float frame_time) {
    auto controller = m_Entity->GetComponent<ControllerComponent>();

    float motion_x = controller->GetMotionX();
    if (motion_x > 0) {
        m_RightSprite->Draw(
                *m_EntityPositionX,
                *m_EntityPositionY,
                *m_EntityWidth,
                *m_EntityHeight,
                0
        );
    } else if (motion_x < 0) {
        m_LeftSprite->Draw(
                *m_EntityPositionX,
                *m_EntityPositionY,
                *m_EntityWidth,
                *m_EntityHeight,
                0
        );
    } else {
        m_StillSprite->Draw(
                *m_EntityPositionX,
                *m_EntityPositionY,
                *m_EntityWidth,
                *m_EntityHeight,
                0
        );
    }
}
