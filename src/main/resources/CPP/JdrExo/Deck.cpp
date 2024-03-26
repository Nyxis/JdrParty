//
// Created by jux on 3/21/24.
//

#include "Deck.hpp"
#include <sstream>
#include "Logger.hpp"
#include "RandomNumberGenerator.hpp"
using RNG = RandomNumberGenerator;

Deck::Deck(int colorsNum)
    : colors(colorsNum)

{
    if (colorsNum == 4)
    {
        this->colors = {1, 2, 3, 4};
        this->values = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    }
    else if (colorsNum == 3)
    {
        this->colors = {1, 2, 3};
        this->values = {
            1, 2, 3, 4, 5, 6, 7, 8, 9,
            10, 11, 12, 13, 14, 15, 16, 17, 18
        };
    }
}

int Deck::tirage()
{
    std::ostringstream oss;
    oss << "le maitre tire une carte au hasard dans son jeu de " << values.size() * colors.size() << std::endl;

    std::string message = oss.str();
    log(message);
;


    return colors[RNG::generate(0, colors.size() - 1)]
        * values[RNG::generate(0, values.size() - 1)];
}
