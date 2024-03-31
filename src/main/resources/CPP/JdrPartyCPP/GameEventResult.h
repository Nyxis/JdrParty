//
// Created by vitsi on 26/03/2024.
//

#ifndef JDRPARTY_GAMEEVENTRESULT_H
#define JDRPARTY_GAMEEVENTRESULT_H

#include <cstdlib>
#include <ctime>

// Enum to represent the possible outcomes of the game event
enum class GameEventResult {
    SUCCESS,
    FAILURE,
    CRITICAL_SUCCESS,
    FUMBLE
};

class GameEvent {
public:
    // Method to simulate the game event and return its result
    static GameEventResult simulateEvent(double successRate, double criticalRate, double failureRate, double fumbleRate);
};

#endif //JDRPARTY_GAMEEVENTRESULT_H

