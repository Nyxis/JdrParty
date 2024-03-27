//
// Created by jux on 3/21/24.
//

#ifndef DECK_H
#define DECK_H
#include <vector>

#include "Logger.hpp"
#include "TirageAction.hpp"

class Deck : protected Logger,public TirageAction{

public:
    int tirage() override;

    Deck(int colorsNum);

private:
    std::vector<int> colors;
    std::vector<int> values;
};

#endif //DECK_H
