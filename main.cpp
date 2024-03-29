#include "src/render/window_context_handler.hpp"
#include "src/physics/physics.hpp"
#include "src/render/renderer.hpp"
#include "src/physics/utils.hpp"
#include "src/read/read_values.hpp"


int main() {

    const uint32_t  window_width = Values::window_width;
    const uint32_t window_height = Values::window_height;
    const int frame_rate = Values::frame_rate;
    WindowContextHandler app("Cloth_Simulation", sf::Vector2u(window_width, window_height), sf::Style::Default, frame_rate);

    PhysicSolver solver;
    Renderer renderer(solver);

    const uint32_t cloth_width  = Values::cloth_width;
    const uint32_t cloth_height = Values::cloth_height;
    const float    links_length = Values::links_length;
    const float    start_x      = (window_width - (cloth_width - 1) * links_length) * 0.5f;
    for (uint32_t y(0); y < cloth_height; ++y) {
        // This is just a formula to make the top links stronger since
        // they are under bigger stress
        const float max_elongation = 1.2f * (2.0f - to<float>(y) / float(cloth_height));
        for (uint32_t x(0); x < cloth_width; ++x) {
            const civ::ID id = solver.addParticle(
                sf::Vector2f(start_x + to<float>(x) * links_length, to<float>(y) * links_length)
            );
            // Add left link if there is a particle on the left
            if (x > 0) {
                solver.addLink(id-1, id, max_elongation * 0.9f);
            }
            // Add top link if there is a particle on the top
            if (y > 0) {
                solver.addLink(id-cloth_width, id, max_elongation);
            } else {
                // If not, pin the particle
                solver.objects[id].moving = false;
            }
        }
    }

    // Drag with right click
    // Erase with middle click
    sf::Vector2f last_mouse_position;
    bool dragging = false;
    bool erasing = false;
    // Add events callback for mouse control
    app.getEventManager().addMousePressedCallback(sf::Mouse::Right, [&](sfev::CstEv) {
        dragging = true;
        last_mouse_position = app.getWorldMousePosition();
    });
    app.getEventManager().addMouseReleasedCallback(sf::Mouse::Right, [&](sfev::CstEv) {
        dragging = false;
    });
    app.getEventManager().addMousePressedCallback(sf::Mouse::Middle, [&](sfev::CstEv) {
        erasing = true;
    });
    app.getEventManager().addMouseReleasedCallback(sf::Mouse::Middle, [&](sfev::CstEv) {
        erasing = false;
    });
    const float applyforce_radius = Values::applyforce_radius;
    const float applyforce_strength = Values::applyforce_strength;
    const float remove_radius = Values::remove_radius;

    // Main loop
    const float time_multiplier = Values::time_multiplier;
    const float dt = (1.0f / to<float>(frame_rate)) * time_multiplier;
    while (app.run()) {
        const sf::Vector2f mouse_position = app.getWorldMousePosition();
        const sf::Vector2f of = app.getMousePosition();

        if (dragging) {
            const sf::Vector2f mouse_speed = mouse_position - last_mouse_position;
            last_mouse_position = mouse_position;
            usr::Utils::applyForceOnCloth(mouse_position, applyforce_radius, mouse_speed * applyforce_strength, solver);
        }

        if (erasing) {
            // Delete all nodes that are in the range of the mouse
            solver.objects.remove_if([&](const Particle& p) {return usr::Utils::isInRadius(p, mouse_position, remove_radius);});
        }

        // Update physics
        solver.update(dt);
        // Render the scene
        RenderContext& render_context = app.getRenderContext();
        render_context.clear();
        renderer.render(render_context);
        render_context.display();
    }
//   sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Cloth-Project", sf::Style::Default);
//   window.setFramerateLimit(60);
//
//   while (window.isOpen()) {
//       sf::Event event;
//
//       while (window.pollEvent(event)) {
//           if (event.type == sf::Event::Closed)
//               window.close();
//       }
//
//       window.clear(sf::Color::Black);
//
//       // draw everything here...
//       // window.draw(...);
//
//       window.display();
//   }

    return 0;
}
