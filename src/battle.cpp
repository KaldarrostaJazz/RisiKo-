#include "battle.hpp"

Battle::Battle(int atk_troops_, int def_troops_)
    : atk_troops{atk_troops_}, def_troops{def_troops_} {
  d6.setSeed(time(NULL));
  if (atk_troops_ <= 0 || def_troops_ <= 0)
    throw std::runtime_error("Troops must be at least one per side.");
}
bool Battle::winner() {
  int troops_left = def_troops;
  int atkng = atk_troops;
  while (troops_left > 0) {
    int atk;
    if (atkng == 0)
      return false;
    else if (atkng >= 3)
      atk = 3;
    else
      atk = atkng;
    int def;
    if (troops_left >= 3)
      def = 3;
    else
      def = troops_left;
    int A[atk];
    int D[def];
    for (int i = 0; i != atk; i++) A[i] = d6.cast();
    for (int i = 0; i != def; i++) D[i] = d6.cast();
    std::sort(A, A + atk, std::greater<int>());
    std::sort(D, D + def, std::greater<int>());
    int min = std::min(atk, def);
    for (int i = 0; i != min; i++) {
      if (A[i] > D[i]) {
        troops_left--;
        def_losses++;
      } else {
        atkng--;
        atk_losses++;
      }
    }
  }
  return true;
}