#include "coin.hpp"
#include <cstdlib>

Coin::Coin(int flips) : flips(flips) {}

RandomResult Coin::generate() const {
    return (flips == 0) ? RandomResult(RandomResult::SUCCESS) : flipCoin();
}

RandomResult Coin::flipCoin() const {
    int result = rand() % 2;
    if (result == 0) return RandomResult(RandomResult::SUCCESS);
    else return flipCoin();
}
