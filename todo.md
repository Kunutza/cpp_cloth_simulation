## To fix

### (All the UPPERCASE will be consts that will be read from a values.txt that will be located next to main.cpp)
main.cpp:  const uint32_t window_width = 1920;
main.cpp:  const uint32_t window_height = 1080;
main.cpp:  const uint32_t cloth_width = 75;
main.cpp:  const uint32_t cloth_height = 50;
main.cpp:  const int frame_rate = 60;
main.cpp:  const float links_lenght = 20.0f;
main.cpp:  const float start_x = (window_width - (cloth_width - 1) * links_length) * 0.5f;
main.cpp:  const float time_multiplier = 10;
main.cpp:  usr::Utils::applyForceOnCloth(mouse_position, 100.0f, mouse_speed * 8000.0f, solver);
main.cpp:  solver.objects.remove_if([&](const Particle& p) {return usr::Utils::isInRadius(p, mouse_position, 10.0f);});

src/physics/particle.cpp: float  mass = 1.0f;

src/physics/constraints.cpp: float distance = 1.0f;
src/physics/constraints.cpp: float strength = 1.0f;
src/physics/constraints.cpp: float max_elongation_ratio = 1.5f;

src/physics/physics.hpp : const sf::Vector2f gravity(0.0f, 1500.0f);
src/physics/physics.hpp : const float friction_coef = 0.5f;
