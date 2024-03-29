#ifndef DICE_HPP
#define DICE_HPP

#include "random_generator.hpp"

class Dice : public RandomGenerator {
public:
    Dice(int faces);

    RandomResult generate() const override;

private:
    int faces;
};

#endif
