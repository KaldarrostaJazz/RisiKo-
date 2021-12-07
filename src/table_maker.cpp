#include "dice.hpp"
#include "battle.hpp"

#include <iostream>
#include <cstring>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Choose an option: --prob || --ratio num\n";
        return 1;
    }
    if (std::strcmp(argv[1], "--prob") != 0 && std::strcmp(argv[1], "--ratio") != 0) {
        std::cerr << "Select a valid option: --prob || --ratio\n";
        return 1;
    }
    int const max_iterations = 1e6;
    int const num = std::stoi(argv[2]);
    for (int k = 0; k != num + 1; k++) {
        if (k == num) std::cout << k;
        else std::cout << k << ',';
    }
    std::cout << std::endl;
    for (int i = 0; i != num; i++) {
        std::cout << i + 1;
        for (int j = 0; j != num; j++) {
            Battle battle{i + 1, j + 1};
            int counter{0};
            for (int it = 0; it != max_iterations; it++) {
                bool winner = battle.winner();
                if (winner == true) counter++;
            }
            if (std::strcmp(argv[1], "--prob") == 0) {
                std::cout << ',' << (double)counter / max_iterations;
            } else if (std::strcmp(argv[1], "--ratio") == 0) {
                double atk_losses = (double)battle.getAtkLosses() / max_iterations;
                double def_losses = (double)battle.getDefLosses() / max_iterations;
                double ratio = atk_losses / def_losses;
                std::cout << ',' << ratio << "/1";
            }
        }
        std::cout << std::endl;   
    }
    return 0;
}