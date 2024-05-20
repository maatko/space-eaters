#ifndef SPACE_EATERS_GRAVITY_H
#define SPACE_EATERS_GRAVITY_H

#include "component.h"

class GravityComponent : public Component {
public:
    explicit GravityComponent(float intensity, bool reset_position);

protected:
    void OnUpdate(float sc_width, float sc_height, float frame_time) override;

private:
    float m_GravityIntensity;
    bool m_ResetPosition;
};

#endif //SPACE_EATERS_GRAVITY_H
