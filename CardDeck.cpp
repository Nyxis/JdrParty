
#include "CardDeck.h"

CardDeck::CardDeck(int numColors, int numValues) : m_numColors(numColors), m_numValues(numValues) {}

int CardDeck::draw() {
    int color = std::rand() % m_numColors + 1;
    int value = std::rand() % m_numValues + 1;
    return (color - 1) * m_numValues + value;
}