#include <iostream>
#include <fstream>
#include <sstream>

std::string read_file(std::string href) {
    std::ostringstream buffer;
    std::ifstream file(href);

    if (file.is_open()) {
        buffer << file.rdbuf();
        file.close();

        return buffer.str();
    }
    return "Unable to open file.";
}

std::string trim(const std::string& s) {
    std::string::const_iterator start = s.begin();
    while (start != s.end() && std::isspace(*start)) {
        ++start;
    }
    std::string::const_iterator end = s.end();
    do {
        --end;
    } while (std::distance(start, end) > 0 && std::isspace(*end));
    return std::string(start, end + 1);
}

size_t find_nth(const std::string& str, char ch, int n) {
    size_t pos = str.find(ch);
    int count = 0;
    while (pos != std::string::npos && count < n) {
        pos = str.find(ch, pos + 1);
        ++count;
    }
    return pos;
}