//
// Created by vitsi on 26/03/2024.
//
#include "Dice.h"
#include <cstdlib>
#include <ctime>
#include "GameEventResult.h"


Dice::Dice(std::vector<int> _faces) : faces(_faces) {}

int Dice::roll(double criticalRate, double failureRate, double fumbleRate) {
    // Seed the random number generator
    srand(time(nullptr));
    int randomIndex = rand() % faces.size();

    // Generate a random number between 0 and 100 to represent the success rate
    int randomValue = rand() % 100;

    // Check if the result is a success, a failure, a critical success, or a fumble
    if (randomValue < criticalRate) {
        // Critical success
        return faces[randomIndex] * 2;
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
        return faces[randomIndex];
    }
}




