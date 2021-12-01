#include "dice.hpp"
#include <iostream>

int main() {
    Dice d6{6};
    Dice d12{12};
    Dice d20{20};
    d6.setSeed(time(NULL));
    d12.setSeed(time(NULL) - 2);
    d20.setSeed(time(NULL) - 1);
    int six_counter[8]{0};
    int twelve_counter[14]{0};
    int twenty_counter[22]{0};
    for (int i = 0; i != 1e7; i++) {
        six_counter[d6.cast()]++;
        twelve_counter[d12.cast()]++;
        twenty_counter[d20.cast()]++;
    }
    std::cout << "#d6" << '\n';
    std::cout << "numero, occorrenze" << '\n';
    for (int i = 0; i != 8; i++) {
        std::cout << i << ',' << six_counter[i] << '\n';
    }
    std::cout << "#d12" << '\n';
    std::cout << "numero,occorrenze" << '\n';
    for (int i = 0; i != 14; i++) {
        std::cout << i << ',' << twelve_counter[i] << '\n';
    }
    std::cout << "#d20" << '\n';
    std::cout << "numero,occorrenze" << '\n';
    for (int i = 0; i != 22; i++) {
        std::cout << i << ',' << twenty_counter[i] << '\n';
    }
}
