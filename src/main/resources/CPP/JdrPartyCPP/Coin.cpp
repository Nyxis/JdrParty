//
// Created by vitsi on 26/03/2024.
//
#include "Coin.h"
#include <cstdlib>
#include <ctime>

Coin::Coin(int _numFlips) : numFlips(_numFlips) {}

bool Coin::flip(double criticalRate, double failureRate, double fumbleRate) {
    // Seed the random number generator
    srand(time(nullptr));
    int count = 0;
    for (int i = 0; i < numFlips; ++i) {
        // Generate a random number between 0 and 100 to represent the success rate
        int randomValue = rand() % 100;

        // Check if the result is a success, a failure, a critical success, or a fumble
        if (randomValue < criticalRate) {
            count += 2; // Critical success
        } else if (randomValue < criticalRate + failureRate) {
            count = -1; // Failure
        } else if (randomValue < criticalRate + failureRate + fumbleRate) {
            count = 0; // Fumble
        } else {
            ++count; // Success
        }
    }
    return count == 1;
}


