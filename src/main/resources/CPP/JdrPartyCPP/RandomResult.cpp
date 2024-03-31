//
// Created by vitsi on 26/03/2024.
//

#include "RandomResult.h"
#include <cstdlib>
#include <ctime>

Result RandomResult::generateResult(double successRate, double criticalRate, double fumbleRate) {
    srand(time(0)); // Seed the random number generator
    double random = rand() % 100 + 1;
    if (random <= successRate) {
        return Result::SUCCESS;
    } else if (random <= successRate + criticalRate) {
        return Result::CRITICAL_SUCCESS;
    } else if (random <= successRate + criticalRate + fumbleRate) {
        return Result::FUMBLE;
    } else {
        return Result::FAILURE;
    }
}
