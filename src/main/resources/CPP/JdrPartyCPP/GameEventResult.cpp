//
// Created by vitsi on 26/03/2024.
//

#include "GameEventResult.h"
#include <cstdlib>
#include <ctime>

GameEventResult GameEvent::simulateEvent(double successRate, double criticalRate, double failureRate, double fumbleRate) {
    // Seed the random number generator  and Use time to seed srand
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random number between 0 and 99
    int randomNumber = rand() % 100;

    // Determine the result based on the success, critical, failure, and fumble rates
    if (randomNumber < successRate) {
        return GameEventResult::SUCCESS;
    } else if (randomNumber < successRate + criticalRate) {
        return GameEventResult::CRITICAL_SUCCESS;
    } else if (randomNumber < successRate + criticalRate + failureRate) {
        return GameEventResult::FAILURE;
    } else if (randomNumber < successRate + criticalRate + failureRate + fumbleRate) {
        return GameEventResult::FUMBLE;
    } else {
        return GameEventResult::FAILURE;
    }
}

