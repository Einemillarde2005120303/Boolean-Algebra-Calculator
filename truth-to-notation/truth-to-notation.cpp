#include <iostream>
#include "../utils/utils.cpp"
#include <windows.h>
#include <unordered_map>
#include <vector>

int main() {
    SetConsoleOutputCP(CP_UTF8);

    const char IN_VARS[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    const char OUT_VARS[] = {'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'};

    bool latex_mode = false;
    std::cout << "latex view (y / n) >> ";
    char latex_choice;
    std::cin >> latex_choice;
    if (latex_choice == 'y' || latex_choice == 'Y') latex_mode = true;
    std::cout << "\n";

    const std::string TRUTH_STR = trim(read_file("../input-file"));

    const size_t IN_LEN = TRUTH_STR.find(':');
    const size_t OUT_LEN = TRUTH_STR.find('\n') - (TRUTH_STR.find(':') + 1);
    const size_t HEIGHT = IN_LEN * IN_LEN;

    std::vector<std::vector<int>> in_vect;
    std::vector<std::vector<int>> out_vect;

    for (size_t i = 0; i < HEIGHT; ++i) {
        std::vector<int> vec;
        size_t n = i == 0 ? 0 : find_nth(TRUTH_STR, '\n', i - 1) + 1;
        for (size_t j = 0; j < IN_LEN; ++j) {
            vec.push_back(TRUTH_STR.at(n + j) - '0');
        }
        in_vect.push_back(vec);
    }

    for (size_t i = 0; i < HEIGHT; ++i) {
        std::vector<int> vec;
        size_t n = find_nth(TRUTH_STR, ':', i) + 1;
        for (size_t j = 0; j < OUT_LEN; ++j) {
            vec.push_back(TRUTH_STR.at(n + j) - '0');
        }
        out_vect.push_back(vec);
    }

    std::vector<std::string> notations;

    for (size_t i = 0; i < OUT_LEN; ++i) {
        std::string str;
        for (size_t j = 0; j < HEIGHT; ++j) {
            if (out_vect[j][i] == 0) continue;

            for (size_t k = 0; k < IN_LEN; ++k) {
                if (in_vect[j][k] != 0) {
                    str.push_back(IN_VARS[k]);
                    continue;
                }
                if (!latex_mode){
                    str.append("\\overline{");
                    str.push_back(IN_VARS[k]);
                    str.append("}");
                    continue;
                }
                str.push_back(IN_VARS[k]);
                str.append("\u0305");
            }
            str.push_back('+');
        }
        if (!str.empty()) str.pop_back();
        notations.push_back(str);
    }

    for (size_t k = 0; k < OUT_LEN; k++) {
        std::cout << OUT_VARS[k] << " = " << notations[k] << "\n";
    }
}