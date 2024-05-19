#include "sprite.h"

#include <spritesheet.h>

#include "controller.h"
#include "../entity.h"

SpriteComponent::SpriteComponent(Sprite up, Sprite left, Sprite down, Sprite right, Sprite still) {
    m_Sprites.insert({SpriteComponent::Direction::UP, up});
    m_Sprites.insert({SpriteComponent::Direction::LEFT, left});
    m_Sprites.insert({SpriteComponent::Direction::DOWN, down});
    m_Sprites.insert({SpriteComponent::Direction::RIGHT, right});
    m_Sprites.insert({SpriteComponent::Direction::STILL, still});
}

void SpriteComponent::OnUpdate(float sc_width, float sc_height, float frame_time) {
    auto controller = m_Entity->GetComponent<ControllerComponent>();
    auto direction = SpriteComponent::Direction::STILL;

    float motionX = controller->GetMotionX();
    if (motionX < 0) {
        direction = SpriteComponent::Direction::LEFT;
    } else if (motionX > 0) {
        direction = SpriteComponent::Direction::RIGHT;
    }

    Sprite sprite = m_Sprites[direction];

    SpriteSheet::Get()->DrawSprite(
            *m_EntityPositionX, *m_EntityPositionY,
            sprite.x, sprite.y,
            *m_EntityWidth, *m_EntityHeight,
            sprite.width, sprite.height,
            sprite.rotation
    );
}
