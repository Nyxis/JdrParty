//
// Created by vitsi on 26/03/2024.
//

#ifndef JDRPARTY_GAMEMASTER_H
#define JDRPARTY_GAMEMASTER_H

#include "GameEventResult.h"
#include "Dice.h"
#include "Coin.h"
#include "Deck.h"
#include <vector>

class GameMaster {
public:
    GameMaster(std::vector<Dice> _dice, std::vector<Coin> _coins, std::vector<Deck> _decks);
    GameEventResult pleaseGiveMeACrit(double criticalRate, double failureRate, double fumbleRate);
private:
    std::vector<Dice> dice;
    std::vector<Coin> coins;
    std::vector<Deck> decks;
};

#endif //JDRPARTY_GAMEMASTER_H
