#include <vector>
#include <iostream>
#include "GameMaster.h"
#include "Logger.h"
#include <cmath>

int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " <critical_rate> <failure_rate> <fumble_rate>" << std::endl;
        return 1;
    }


    float criticalRate = std::atof(argv[1]);
    float failureRate = std::atof(argv[2]);
    float fumbleRate = std::atof(argv[3]);

   // std::cout << "Critical Rate: " << criticalRate << "%" << std::endl;
    //std::cout << "Failure Rate: " << failureRate << "%" << std::endl;
   // std::cout << "Fumble Rate: " << fumbleRate << "%" << std::endl;

    Logger::log("Critical Rate: " + std::to_string(static_cast<int>(criticalRate * 100)) + "%", Logger::LogType::INFO);
    Logger::log("Failure Rate: " + std::to_string(static_cast<int>(failureRate * 100)) + "%", Logger::LogType::INFO);
    Logger::log("Fumble Rate: " + std::to_string(static_cast<int>(fumbleRate * 100)) + "%", Logger::LogType::INFO);

     // Creating instances of Dice, Coin, and Deck
    std::vector<Dice> dice = {Dice({1, 2, 3, 4, 5, 6}), Dice({1, 2, 3, 4, 5, 6, 7, 8})};
    std::vector<Coin> coins = {Coin(1), Coin(2)};
    std::vector<Deck> decks = {Deck(3, 18), Deck(4, 13)};

    // Creating the GameMaster object with the constructed dice, coins, and decks
    GameMaster gm(dice, coins, decks);

    // Generating a result for the game event using the GameMaster
    GameEventResult result = gm.pleaseGiveMeACrit(criticalRate, failureRate, fumbleRate);

    // Handling the result of the game event
    switch (result) {
        case GameEventResult::SUCCESS:
            Logger::log("The game event was a success!", Logger::LogType::INFO);
            break;
        case GameEventResult::FAILURE:
            Logger::log("The game event failed.", Logger::LogType::WARNING);
            break;
        case GameEventResult::CRITICAL_SUCCESS:
            Logger::log("Critical success!", Logger::LogType::INFO);
            break;
        case GameEventResult::FUMBLE:
            Logger::log("Fumble! The game event went terribly wrong.", Logger::LogType::ERROR);
            break;
    }

    return 0;
}



