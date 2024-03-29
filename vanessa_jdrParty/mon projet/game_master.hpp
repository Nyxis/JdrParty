#ifndef GAME_MASTER_HPP
#define GAME_MASTER_HPP

#include <vector>
#include "random_generator.hpp"
#include "random_result.hpp"

class GameMaster {
public:
    GameMaster();
    ~GameMaster();

    RandomResult pleaseGiveMeAResult(double successRate, double critRate, double fumbleRate) const;

private:
    std::vector<Dice*> dices;
    std::vector<Coin*> coins;
    std::vector<Deck*> decks;
};

#endif
