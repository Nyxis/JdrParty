//
// Created by jux on 3/21/24.
//

#ifndef DICE_H
#define DICE_H
#include <vector>

#include "Logger.hpp"
#include "TirageAction.hpp"

class Dice : public Logger,public TirageAction{

public:
    int tirage() override;
    Dice(int faceNum);
private:
    std::vector<int> faces;

};



#endif //DICE_H
