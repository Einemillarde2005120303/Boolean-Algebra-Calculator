#include <iostream>
#include "../utils/utils.cpp"
#include <windows.h>
#include <unordered_map>
#include <vector>

int main() {
    SetConsoleOutputCP(CP_UTF8);

    const char IN_VARS[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    bool latex_mode = false;
    std::cout << "latex view (y / n) >> ";
    char latex_choice;
    std::cin >> latex_choice;
    if (latex_choice == 'y' || latex_choice == 'Y') latex_mode = true;
    std::cout << "\n";

    const std::string TRUTH_STR = trim(read_file("../input-file"));

    const size_t IN_LEN = TRUTH_STR.find(':');
    const size_t HEIGHT = IN_LEN * IN_LEN;

    std::vector<std::vector<int>> in_vect;
    std::vector<int> out_vect;

    for (size_t i = 0; i < HEIGHT; ++i) {
        std::vector<int> vec;
        size_t n = i == 0 ? 0 : find_nth(TRUTH_STR, '\n', i - 1) + 1;
        for (size_t j = 0; j < IN_LEN; ++j) {
            vec.push_back(TRUTH_STR.at(n + j) - '0');
        }
        in_vect.push_back(vec);
    }

    for (size_t i = 0; i < HEIGHT; ++i) {
        size_t n = find_nth(TRUTH_STR, ':', i) + 1;
        out_vect.push_back(TRUTH_STR.at(n) - '0');
    }

    std::string notation;
    for (size_t i = 0; i < HEIGHT; ++i) {
        if (out_vect[i] == 0) continue;

        for (size_t j = 0; j < IN_LEN; ++j) {
            if (in_vect[i][j] != 0) {
                notation.push_back(IN_VARS[j]);
                continue;
            }
            if (!latex_mode){
                notation.append("\\overline{");
                notation.push_back(IN_VARS[j]);
                notation.append("}");
                continue;
            }
            notation.push_back(IN_VARS[j]);
            notation.append("\u0305");
        }
        notation.push_back('+');
    }
    if (!notation.empty()) notation.pop_back();

    std::cout << notation << "\n";
}