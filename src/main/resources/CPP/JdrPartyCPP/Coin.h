//
// Created by vitsi on 26/03/2024.
//

#ifndef JDRPARTY_COIN_H
#define JDRPARTY_COIN_H

#include "GameEventResult.h"
#include "Logger.h"

class Coin {
public:
    Coin(int _numFlips);
    bool flip(double criticalRate, double failureRate, double fumbleRate);
private:
    int numFlips;
};


#endif //JDRPARTY_COIN_H
