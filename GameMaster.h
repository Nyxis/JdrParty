
#ifndef MMADI_MOURTADHOI_GAMEMASTER_H
#define MMADI_MOURTADHOI_GAMEMASTER_H

#include <vector>
#include "Die.h"
#include "Coin.h"
#include "CardDeck.h"


class GameMaster {
 public:
    GameMaster();

    static const int SUCCESS = 0;
    static const int CRITICAL_SUCCESS = 1;
    static const int FUMBLE = 2;

    int pleaseGiveMeACrit(int successRate, int criticalRate, int fumbleRate);

 private:
    std::vector<Die> m_dices;
    std::vector<Coin> m_coins;
    std::vector<CardDeck> m_cardDecks;
};


#endif //MMADI_MOURTADHOI_GAMEMASTER_H
