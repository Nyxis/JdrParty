
#include "Coin.h"


Coin::Coin(int numFlips) : m_numFlips(numFlips) {}

int Coin::flip() {

    if (m_numFlips == 1) {
        return std::rand() % 2;
    }


    int result = flip();
    return (result == 1 && m_numFlips > 1) ? flip() : 0;
}