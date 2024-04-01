//
// Created by vitsi on 26/03/2024.
//

#ifndef JDRPARTY_DICE_H
#define JDRPARTY_DICE_H

#include <vector>


class Dice {
public:
    Dice(std::vector<int> _faces);
    int roll(double criticalRate, double failureRate, double fumbleRate);
private:
    std::vector<int> faces;
};


#endif //JDRPARTY_DICE_H
