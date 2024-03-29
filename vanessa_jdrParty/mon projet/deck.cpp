#include "deck.hpp"
#include <cstdlib>

Deck::Deck(int colors, int values) : colors(colors), values(values), currentColor(0), currentDraw(0) {}

RandomResult Deck::generate() const {
    if (currentDraw == 0) {
        currentColor = rand() % colors + 1;
        currentDraw++;
        return RandomResult(RandomResult::SUCCESS);
    } else if (currentDraw == 1) {
        int value = rand() % values + 1;
        currentDraw++;
        return RandomResult(RandomResult::SUCCESS);
    } else {
        currentDraw = 0;
        return RandomResult(RandomResult::SUCCESS);
    }
}
