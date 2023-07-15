#include "read_values.hpp"


map<string, string> Reader::default_values_map = {
    {"window_width", "1920"},
    {"window_height", "1080"},
    {"frame_rate", "60"},
    {"time_multiplier", "10.0"},
    {"cloth_width", "75"},
    {"cloth_height", "50"},
    {"links_length", "20.0"},
    {"applyforce_radius", "100.0"},
    {"applyforce_strength", "8000.0"},
    {"remove_radius", "10.0"},
    {"mass", "1.0"},
    {"strength", "1.0"},
    {"max_elongation_ratio", "1.5"}
};

const string Reader::values = Reader::getFileAsString("values.txt");

// main.cpp
const uint32_t Values::window_width = stoi(Reader::get_value(Reader::values, "window_width"));
const uint32_t Values::window_height = stoi(Reader::get_value(Reader::values, "window_height"));
const int      Values::frame_rate = stoi(Reader::get_value(Reader::values, "frame_rate"));
const float    Values::time_multiplier = stof(Reader::get_value(Reader::values, "time_multiplier"));
const uint32_t Values::cloth_width = stoi(Reader::get_value(Reader::values, "cloth_width"));
const uint32_t Values::cloth_height = stoi(Reader::get_value(Reader::values, "cloth_height"));
const float    Values::links_length = stof(Reader::get_value(Reader::values, "links_length"));
const float    Values::applyforce_radius = stof(Reader::get_value(Reader::values, "applyforce_radius"));
const float    Values::applyforce_strength = stof(Reader::get_value(Reader::values, "applyforce_strength"));
const float    Values::remove_radius = stof(Reader::get_value(Reader::values, "remove_radius"));

// src/physics/particle.cpp
float          Values::mass = stof(Reader::get_value(Reader::values, "mass"));
float          Values::strength = stof(Reader::get_value(Reader::values, "strength"));

// src/physics/constraints.cpp
float          Values::max_elongation_ratio = stof(Reader::get_value(Reader::values, "max_elongation_ratio"));

// src/physics/physics.hpp
