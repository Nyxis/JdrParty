
#include <vector>
#include "GameMaster.h"
#include "Logger.h"
#include <cmath>
#include <iostream>

    int main(int argc, char* argv[]) {
        if (argc != 4) {
            std::cerr << "Usage: " << argv[0] << " <criticalRate> <failureRate> <fumbleRate>" << std::endl;
            return 1;
        }

        // Retrieve rates from command line
        double criticalRate = std::stod(argv[1]);
        double failureRate = std::stod(argv[2]);
        double fumbleRate = std::stod(argv[3]);

        // Printing the received arguments
        std::cout << "Critical Rate: " << criticalRate << std::endl;
        std::cout << "Failure Rate: " << failureRate << std::endl;
        std::cout << "Fumble Rate: " << fumbleRate << std::endl;

    Logger::log("Critical Rate: " + std::to_string(static_cast<int>(std::round(criticalRate))) + "%", Logger::LogType::INFO);
    Logger::log("Failure Rate: " + std::to_string(static_cast<int>(std::round(failureRate))) + "%", Logger::LogType::INFO);
    Logger::log("Fumble Rate: " + std::to_string(static_cast<int>(std::round(fumbleRate))) + "%", Logger::LogType::INFO);
    // Create instances of Dice, Coin, and Deck
    std::vector<Dice> dice = {Dice({1, 2, 3, 4, 5, 6}), Dice({1, 2, 3, 4, 5, 6, 7, 8})};
    std::vector<Coin> coins = {Coin(1), Coin(2)};
    std::vector<Deck> decks = {Deck(3, 18), Deck(4, 13)};

    // Create the GameMaster object with the constructed dice, coins, and decks
    GameMaster gm(dice, coins, decks);

    // Generate a result for the game event using the GameMaster
    GameEventResult result = gm.pleaseGiveMeACrit(criticalRate, failureRate, fumbleRate);

    // Handle the result of the game event
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


