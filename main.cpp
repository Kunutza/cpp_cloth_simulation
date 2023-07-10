#include <iostream>
#include <cstdio>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "src/physics/particle.hpp"

int main() {
    const uint32_t window_width = 800;
    const uint32_t window_height = 600;

    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Cloth-Project", sf::Style::Default);
    window.setFramerateLimit(60);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);

        window.display();
    }

    return 0;
}
