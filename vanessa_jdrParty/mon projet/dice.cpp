#include "dice.hpp"
#include <cstdlib>

Dice::Dice(int faces) : faces(faces) {}

RandomResult Dice::generate() const {
    int roll = rand() % faces + 1;
    if (roll == 1) return RandomResult(RandomResult::CRIT_SUCCESS);
    else if (roll == faces) return RandomResult(RandomResult::FUMBLE);
    else if (roll <= faces / 2) return RandomResult(RandomResult::SUCCESS);
    else return RandomResult(RandomResult::FAILURE);
}