#include "GameMaster.h"
#include "../gameTypes/coin/Coin.h"
#include "../gameTypes/dice/Dice.h"
#include "../gameTypes/gameCard/gameCard.h"
#include "../tools/randomGenerator/RandomGenerator.h"

float GameMaster::pleaseGiveMeACrit(int success, int critical, int fumble) {
    return (success + critical + fumble)/100;
}

void GameMaster::startRolling() {
    Logger::log(Logger::start);
    int random = RandomGenerator::getRandom(1, 3);
    float plsGiveCrit = this->pleaseGiveMeACrit(RandomGenerator::getRandom(1, 100),
                                              RandomGenerator::getRandom(1, 100),
                                              RandomGenerator::getRandom(1, 100));
    switch (random) {
        case 1: {
            Logger::gameTypeLog("Coin");
            Coin coin;
            Logger::log(Logger::coin);
            coin.rolling(plsGiveCrit);
            coin.showResult();
            Logger::log(Logger::end);
            break;
        }
        case 2: {
            Logger::gameTypeLog("Dice");
            Dice dice;
            Logger::log(Logger::dices);
            dice.rolling(plsGiveCrit);
            dice.showResult();
            Logger::log(Logger::end);
            break;
        }
        case 3: {
            Logger::gameTypeLog("Cards");
            GameCard cards;
            Logger::log(Logger::cards);
            cards.rolling(plsGiveCrit);
            cards.showResult();
            Logger::log(Logger::end);
            break;
        }
    }
}
