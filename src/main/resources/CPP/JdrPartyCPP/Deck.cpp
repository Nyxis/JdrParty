//
// Created by vitsi on 26/03/2024.
//

#include "Deck.h"
#include <cstdlib>
#include <ctime>
#include <vector>

Deck::Deck(int _numColors, int _numValues) : numColors(_numColors), numValues(_numValues) {}

int Deck::draw(double criticalRate, double failureRate, double fumbleRate) {
    // Seed the random number generator
    srand(time(nullptr));
    int color = rand() % numColors + 1;
    int value = rand() % numValues + 1;

    // Generate a random number between 0 and 100 to represent the success rate
    int randomValue = rand() % 100;

    // Check if the result is a success, a failure, a critical success, or a fumble
    if (randomValue < criticalRate) {
        // Critical success
        return (color - 1) * numValues + value + 1000; // Add an arbitrary number to represent a critical success
    } else if (randomValue < criticalRate + failureRate) {
        // Failure
        // Return -1 to represent a failure
        return -1;
    } else if (randomValue < criticalRate + failureRate + fumbleRate) {
        // Fumble
        // Return 0 to represent a fumble
        return 0;
    } else {
        // Success
        return (color - 1) * numValues + value;
    }
}

