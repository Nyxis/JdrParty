//
// Created by jux on 3/21/24.
//

#include "Dice.hpp"
#include <iostream>
#include <sstream>
#include "Logger.hpp"
#include "RandomNumberGenerator.hpp"
using RNG = RandomNumberGenerator;

Dice::Dice(int faceNum)

{
    faceNum == 6 ?this->faces = {1, 2, 3, 4, 5, 6}
        :faceNum == 10 ? this->faces = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
        : this->faces = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
}

int Dice::tirage()
{

    std::ostringstream oss;
    oss << "le maitre du jeu lance un dé de "<<this->faces.size()<<" faces" << std::endl;
    std::string message = oss.str();
    log(message);
;

    int score = faces[RNG::generate(0, faces.size()-1)];

    return faces.size() == 6 ? score*10
        : faces.size() == 10 ? score*5
        : score*3;
}
