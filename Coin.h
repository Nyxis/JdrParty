
#ifndef MMADI_MOURTADHOI_COIN_H
#define MMADI_MOURTADHOI_COIN_H

#include "RandomDrawResult.h"

class Coin : public RandomDrawResult {
public:
    Coin(int numFlips);

    int flip() override;

private:
    int m_numFlips;
};


#endif //MMADI_MOURTADHOI_COIN_H
