#ifndef DICE_HPP
#define DICE_HPP
#include <cstdlib>
#include <stdexcept>

class Dice {
 public:
  Dice(int faces);
  int cast();
  void setSeed(long unsigned int seed);
  int getFaces() { return faces_; }
  void setFaces(int num) { faces_ = num; }

 private:
  int faces_;
};
#endif
