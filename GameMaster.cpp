#include "GameMaster.h"

#include "Dice.h"

#include "Deck.h"
#include "Coin.h"
#include <string>





std::string Maitre::PleaseGiveMeACrit() {

    int result = (rand() % 2);
    if (result == 1) {
        return Coin::flip() ;

    } else {
        return Dice::randomDice();
    }

}