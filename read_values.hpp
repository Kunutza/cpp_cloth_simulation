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

    static const string get_value(const string stringfile, const string value_name) {
        regex rgx(value_name + "=(\\w+)");
        smatch match;

        if (regex_search(stringfile.begin(), stringfile.end(), match, rgx))
            return match[1];
        return default_values_map.find(value_name)->second; 
    }
};
