//
// Created by vitsi on 26/03/2024.
//

#ifndef JDRPARTY_RANDOMRESULT_H
#define JDRPARTY_RANDOMRESULT_H

enum class Result {
    SUCCESS,
    FAILURE,
    CRITICAL_SUCCESS,
    FUMBLE
};

class RandomResult {
public:
    static Result generateResult(double successRate, double criticalRate, double fumbleRate);
};

#endif //JDRPARTY_RANDOMRESULT_H

