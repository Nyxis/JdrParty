//
// Created by jux on 3/21/24.
//

#include "Coin.hpp"

#include <iomanip>
#include <iostream>
#include <strstream>

#include "Logger.hpp"
#include "RandomNumberGenerator.hpp"
using RNG = RandomNumberGenerator;


Coin::Coin(int nbLancers)
    : nbLancers(nbLancers)
{
    this->nbLancers = nbLancers;
    this->lancersReussis = 0;
}

int Coin::tirage()

{

    std::ostringstream oss;
    oss << "le maitre du jeu lance une pièce une " << lancersReussis + 1 << "e fois" << std::endl;


    std::string message = oss.str();
    log(message);




    bool result = RNG::generate(0, 1);
    result
        ? this->lancersReussis++
        : result = 0;

    return result == 0
               ? 0
               : this->lancersReussis == nbLancers
               ? 1
               : this->tirage();
}
