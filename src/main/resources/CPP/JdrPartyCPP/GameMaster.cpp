#include "GameMaster.h"
#include "Logger.h"
#include <cstdlib>
#include <ctime>
#include "GameEventResult.h"

GameMaster::GameMaster(std::vector<Dice> _dice, std::vector<Coin> _coins, std::vector<Deck> _decks)
        : dice(_dice), coins(_coins), decks(_decks) {}

GameEventResult GameMaster::pleaseGiveMeACrit(double criticalRate, double failureRate, double fumbleRate) {

    // Seed the random number generator
    srand(time(nullptr));
    int randomIndex = rand() % (dice.size() + coins.size() + decks.size());
    if (randomIndex < dice.size()) {
        // Roll the dice
        Logger::log("Using a dice to generate the result.", Logger::LogType::INFO);
        int rollResult = dice[randomIndex].roll(criticalRate, failureRate, fumbleRate);
        // Convert the roll result to a Result object
        if (rollResult > 0) {
            return GameEventResult::SUCCESS;
        } else if (rollResult < 0) {
            return GameEventResult::FAILURE;
        } else {
            return GameEventResult::FUMBLE;
        }
    } else if (randomIndex < dice.size() + coins.size()) {
        // Flip the coin
        Logger::log("Using a coin to generate the result.", Logger::LogType::INFO);
        bool flipResult = coins[randomIndex - dice.size()].flip(criticalRate, failureRate, fumbleRate);
        // Convert the flip result to a Result object
        if (flipResult) {
            return GameEventResult::SUCCESS;
        } else {
            return GameEventResult::FAILURE;
        }
    } else {
        // Draw from the deck
        Logger::log("Using a deck of cards to generate the result.", Logger::LogType::INFO);
        int drawResult = decks[randomIndex - dice.size() - coins.size()].draw(criticalRate, failureRate, fumbleRate);
        // Convert the draw result to a Result object
        if (drawResult > 0) {
            return GameEventResult::SUCCESS;
        } else if (drawResult < 0) {
            return GameEventResult::FAILURE;
        } else {
            return GameEventResult::FUMBLE;
        }
    }
}



