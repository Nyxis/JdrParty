#ifndef COIN_HPP
#define COIN_HPP

#include "random_generator.hpp"

class Coin : public RandomGenerator {
public:
    Coin(int flips);

    RandomResult generate() const override;

private:
    int flips;

    RandomResult flipCoin() const;
};

#endif
