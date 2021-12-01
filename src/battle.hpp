#ifndef BATTLE_HPP
#define BATTLE_HPP
#include "dice.hpp"
#include <algorithm>
#include <functional>

class Battle {
    public:
        Battle(int atk_troops_, int def_troops_);
        bool winner();
        int getAtkLosses() { return atk_losses; }
        int getDefLosses() { return def_losses; }
    private:
        int atk_troops;
        int def_troops;
        int atk_losses{0};
        int def_losses{0};
        Dice d6{6};
};
#endif