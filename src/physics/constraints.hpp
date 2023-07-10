#pragma once

#include <SFML/System/Vector2.hpp>
#include "particle.hpp"
#include "../math/math.hpp"

class LinkConstraint {
    public:
        civ::ID id = 0;

        float distance = 1.0f;
        float strength = 1.0f;
        float max_elongation_ratio = 1.5f;

        Particle particle_1;
        Particle particle_2;

        bool broken = false;

        LinkConstraint() = default;

        LinkConstraint(Particle p_1, Particle p_2) : particle_1(p_1), particle_2(p_2) {
            distance = MathVec2::length(p_1.position - p_2.position);
        }

        [[nodiscard]]
        bool isValid() const {
            return particle_2 && particle_1 && !broken;
        }

        void solve() {
            if (!isValid()) { return; }
            Particle& p_1 = *particle_1;
            Particle& p_2 = *particle_2;
            const sf::Vector2f v = p_1.position - p_2.position;
            const float dist = MathVec2::length(v);
            if (dist > distance) {
                // Break if the distance is over the given threshold
                broken = dist > distance * max_elongation_ratio;
                const sf::Vector2f n = v / dist;
                const float c = distance - dist;
                const sf::Vector2f p = -(c * strength) / (p_1.mass + p_2.mass) * n;
                // Apply position correction
                p_1.move(-p / p_1.mass);
                p_2.move( p / p_2.mass);
            }
        }
};
