#ifndef DECK_HPP
#define DECK_HPP

#include "random_generator.hpp"

class Deck : public RandomGenerator {
public:
    Deck(int colors, int values);

    RandomResult generate() const override;

private:
    int colors;
    int values;
    mutable int currentColor;
    mutable int currentDraw;
};

#endif
