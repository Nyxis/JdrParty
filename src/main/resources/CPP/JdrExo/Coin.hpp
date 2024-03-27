//
// Created by jux on 3/21/24.
//

#ifndef COIN_H
#define COIN_H

#include "Logger.hpp"
#include "TirageAction.hpp"

class Coin : public TirageAction, Logger

{
public:
    int tirage() override;

    Coin(int nbLancers);

private:
    int nbLancers;
    int lancersReussis;
};

#endif //COIN_H
