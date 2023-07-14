#pragma once

#include <regex>
#include <fstream>
#include <map>

using namespace std;

struct Reader {
    bool failed = false;

    static map<string, string>default_values_map;

    static const string getFileAsString(string file_name = "values.txt") {
        ifstream stringfile(file_name);
        const string str((istreambuf_iterator<char>(stringfile)), istreambuf_iterator<char>());

        return str;
    }

    static const string get_window_width(const string stringfile) {
        regex rgx("window_width=(\\w+)");
        smatch match;

        if (regex_search(stringfile.begin(), stringfile.end(), match, rgx))
            return match[1];
        return default_values_map.find("window_width")->second;
    }


    static const string get_window_height(const string stringfile) {
        regex rgx("window_height=(\\w+)");
        smatch match;

        if (regex_search(stringfile.begin(), stringfile.end(), match, rgx))
            return match[1];
        return default_values_map.find("window_height")->second;
    }


    static const string get_frame_rate(const string stringfile) {
        regex rgx("frame_rate=(\\w+)");
        smatch match;

        if (regex_search(stringfile.begin(), stringfile.end(), match, rgx))
            return match[1];
        return default_values_map.find("frame_rate")->second;
    }

    static const string get_time_multitplier(const string stringfile) {
        regex rgx("time_multiplier=(\\w+)");
        smatch match;

        if (regex_search(stringfile.begin(), stringfile.end(), match, rgx))
            return match[1];
        return default_values_map.find("time_multiplier")->second;
    }

    static const string get_cloth_width(const string stringfile) {
        regex rgx("cloth_width=(\\w+)");
        smatch match;

        if (regex_search(stringfile.begin(), stringfile.end(), match, rgx))
            return match[1];
        return default_values_map.find("cloth_width")->second;
    }


    static const string get_cloth_height(const string stringfile) {
        regex rgx("cloth_height=(\\w+)");
        smatch match;

        if (regex_search(stringfile.begin(), stringfile.end(), match, rgx))
            return match[1];
        return default_values_map.find("cloth_height")->second;
    }


    static const string get_links_lenght(const string stringfile) {
        regex rgx("links_length=(\\w+)");
        smatch match;

        if (regex_search(stringfile.begin(), stringfile.end(), match, rgx))
            return match[1];
        return default_values_map.find("links_length")->second;
    }
};
