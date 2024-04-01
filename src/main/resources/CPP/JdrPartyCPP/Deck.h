//
// Created by vitsi on 26/03/2024.
//

#ifndef JDRPARTY_DECK_H
#define JDRPARTY_DECK_H


#include "GameEventResult.h"
#include "Logger.h"

class Deck {
public:
    Deck(int _numColors, int _numValues);
    int draw(double criticalRate, double failureRate, double fumbleRate);
private:
    int numColors;
    int numValues;
};
#endif //JDRPARTY_DECK_H
