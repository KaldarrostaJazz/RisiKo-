#include <algorithm>
#include <iostream>

#include "dice.hpp"
#include "battle.hpp"

int main(int argc, char* argv[]) {
  try {
    if (argc < 3) {
      std::cerr << "Usage: " << argv[0] << " #atk_troops #def_troops\n"
                << "Floating point numbers will be converted to integer "
                << "by considering their integer part\n";
      return 1;
    }
    int atk = std::stoi(argv[1]); // better way of converting?
    int def = std::stoi(argv[2]); // better way of converting?
    Battle battle{atk, def};
    int iterations{10000000}; // 1e7 iterations
    int counter{0};
    for (int i = 0; i != iterations; i++) {
      bool winner = battle.winner();
      if (winner == true) counter++;
    }
    double ALosses = battle.getAtkLosses();
    double DLosses = battle.getDefLosses();
    std::cout << "Probabilty of " << atk << " vs " << def << " : " << (double)counter / iterations << '\n';
    std::cout << "Avg. lost troops:\n" << "Atk: " << ALosses / iterations 
              << " Def: " << DLosses / iterations << '\n';
    std::cout << "Ratio AtkLosses/DefLosses: " << ALosses / DLosses << '/' << "1\n";
    return 0;
  } catch (std::exception& error) {
    std::cerr << error.what() << '\n';
    return 1;
  }
}