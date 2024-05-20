#ifndef SPACE_EATERS_GRAVITY_H
#define SPACE_EATERS_GRAVITY_H

#include "component.h"

class GravityComponent : public Component {
public:
    explicit GravityComponent(float intensity);

protected:
    void OnUpdate(float sc_width, float sc_height, float frame_time) override;

private:
    float m_GravityIntensity;
};

#endif //SPACE_EATERS_GRAVITY_H
