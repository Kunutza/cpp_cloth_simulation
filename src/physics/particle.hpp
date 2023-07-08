#pragma once

#include <SFML/System/Vector2.hpp>

class Particle {
    public:
        float  mass = 1.0f;

        bool moving = true;

        sf::Vector2f position;
        sf::Vector2f old_position;
        sf::Vector2f velocity;
        sf::Vector2f forces;

        // Explicit so that you can not use copy initialization
        explicit Particle(sf::Vector2f pos) : position(pos), old_position(pos) {}

        void update(float dt) {
            if(!moving) return;
            old_position = position;
            velocity = (forces / mass) * dt;
            position += velocity * dt;
        }

        void update_derivatives(float dt) {
            velocity = (position - old_position) / dt;
            forces = {};
        }

        void move(sf::Vector2f v) {
            if (!moving) return;
            position += v;
        }
};
