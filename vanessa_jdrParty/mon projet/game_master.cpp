#include "game_master.hpp"
#include "dice.hpp"
#include "coin.hpp"
#include "deck.hpp"
#include <cstdlib>
#include <ctime>

GameMaster::GameMaster() {

    srand(time(NULL));

    dices.push_back(new Dice(6));

    coins.push_back(new Coin(2));

    decks.push_back(new Deck(3, 18));
    decks.push_back(new Deck(4, 13));
}

GameMaster::~GameMaster() {

    for (auto dice : dices) delete dice;
    for (auto coin : coins) delete coin;
    for (auto deck : decks) delete deck;
}

RandomResult GameMaster::pleaseGiveMeAResult(double successRate, double critRate, double fumbleRate) const {

    int randomIndex = rand() % (dices.size() + coins.size() + decks.size());
    if (randomIndex < dices.size()) {
        return dices[randomIndex]->generate();
    } else if (randomIndex < dices.size() + coins.size()) {
        return coins[randomIndex - dices.size()]->generate();
    } else {
        return decks[randomIndex - dices.size() - coins.size()]->generate();
    }
}
