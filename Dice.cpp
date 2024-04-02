#include "Dice.h"
#include <cstdlib>
#include <string>



Dice::Dice(int dice) {


};

std::string Dice::randomDice(){
    int resultDice = (rand() % 6) + 1; // Pour obtenir un résultat entre 1 et 6
    return std::to_string(resultDice);
}