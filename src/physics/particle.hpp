#pragma once

#include <SFML/System/Vector2.hpp>
#include "../math/index_vector.hpp"

struct Particle {
    civ::ID id = 0;

    float  mass = 1.0f;

    bool moving = true;

    sf::Vector2f position;
    sf::Vector2f old_position;
    sf::Vector2f velocity;
    sf::Vector2f forces;

    Particle() = default;

    // Explicit so that you can not use copy initialization
    explicit Particle(sf::Vector2f pos) : position(pos), old_position(pos) {}

    void update(float dt) {
        if(!moving) return;
        old_position = position;
        velocity = (forces / mass) * dt;
        position += velocity * dt;
    }

    void updateDerivatives(float dt) {
        velocity = (position - old_position) / dt;
        forces = {};
    }

    void move(sf::Vector2f v) {
        if (!moving) return;
        position += v;
    }
};

using ParticleRef = civ::Ref<Particle>;
