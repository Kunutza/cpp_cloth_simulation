#pragma once

#include <atomic>
#include <cstdio>
#include <regex>
#include <fstream>
#include <map>

#include <iostream>

using namespace std;

struct Reader {
    bool failed = false;

    static map<string, string>default_values_map;
    static const string values;

    static const string getFileAsString(string file_name) {
        ifstream stringfile(file_name);
        const string str((istreambuf_iterator<char>(stringfile)), istreambuf_iterator<char>());

        return str;
    }
    
    static const string get_value(const string stringfile, const string value_name) {
        regex rgx(" " + value_name + "=(\\w+(\\.\\w+)?)");
        smatch match;

        if (regex_search(stringfile.begin(), stringfile.end(), match, rgx)) {
            cout << "did" << '\n';
            cout << value_name.c_str() << '\n';
            cout << match[1] << '\n';
            return match[1];
        }

        cout << "failed" << '\n';
        return default_values_map.find(value_name)->second; 
    }
};


struct Values {
    // main.cpp
    static const uint32_t window_width; 
    static const uint32_t window_height;
    static const int frame_rate;
    static const float time_multiplier;
    static const uint32_t cloth_width;
    static const uint32_t cloth_height;
    static const float links_length;
    static const float applyforce_radius;
    static const float applyforce_strength;
    static const float remove_radius;

    // src/physics/particle.cpp
    static float mass;

    // src/physics/constraints.cpp
    static float distance;
    static float strength;
    static float max_elongation_ratio;

    // src/physics/physics.hpp
};
