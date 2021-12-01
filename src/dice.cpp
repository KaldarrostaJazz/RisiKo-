#include "dice.hpp"
Dice::Dice(int faces) : faces_{faces} {
  if (faces <= 0)
    throw std::runtime_error("The dice must have at least 1 face\n");
}
int Dice::cast() {
  int random_num = rand() % faces_ + 1; 
  return random_num;
}
void Dice::setSeed(long unsigned int seed) { srand(seed); }
