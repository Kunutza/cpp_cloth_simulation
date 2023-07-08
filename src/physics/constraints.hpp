#pragma once

#include <SFML/System/Vector2.hpp>
#include "particle.hpp"

class LinkConstraints {
    public:
        float distance = 1.0f;
        float strength = 1.0f;
        float max_elongation_ratio = 1.5f;

        Particle particle_1;
        Particle particle_2;

        bool broken = false;
         
};
