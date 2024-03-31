#include "GameMaster.h"
#include "Logger.h"
#include <random> a cha
#include "GameEventResult.h"

// Declare random number generator globally
std::mt19937 rng(std::random_device{}());

GameMaster::GameMaster(std::vector<Dice> _dice, std::vector<Coin> _coins, std::vector<Deck> _decks)
        : dice(_dice), coins(_coins), decks(_decks) {}

GameEventResult GameMaster::pleaseGiveMeACrit(double criticalRate, double failureRate, double fumbleRate) {
    // Use the random number generator to get a random index
    std::uniform_int_distribution<int> distribution(0, dice.size() + coins.size() + decks.size() - 1);
    int randomIndex = distribution(rng);

    if (randomIndex < dice.size()) {
        // Roll the dice
        Logger::log("Using a dice to generate the result.", Logger::LogType::INFO);
        int rollResult = dice[randomIndex].roll(criticalRate, failureRate, fumbleRate);
        if (rollResult > 0) {
            return GameEventResult::SUCCESS;
        } else if (rollResult < 0) {
            // Introduce a chance for failure
            if (failureRate > 0.0 && rng() % 100 < failureRate * 100) {
                return GameEventResult::FAILURE;
            }
            // Introduce a chance for fumble
            if (fumbleRate > 0.0 && rng() % 100 < fumbleRate * 100) {
                return GameEventResult::FUMBLE;
            }
            return GameEventResult::FAILURE;
        } else {
            // Introduce a chance for fumble
            if (fumbleRate > 0.0 && rng() % 100 < fumbleRate * 100) {
                return GameEventResult::FUMBLE;
            }
            // Introduce a chance for failure
            if (failureRate > 0.0 && rng() % 100 < failureRate * 100) {
                return GameEventResult::FAILURE;
            }
            return GameEventResult::FAILURE;
        }
    } else if (randomIndex < dice.size() + coins.size()) {
        // Flip the coin
        Logger::log("Using a coin to generate the result.", Logger::LogType::INFO);
        bool flipResult = coins[randomIndex - dice.size()].flip(criticalRate, failureRate, fumbleRate);
        if (flipResult) {
            return GameEventResult::SUCCESS;
        } else {
            // Introduce a chance for failure
            if (failureRate > 0.0 && rng() % 100 < failureRate * 100) {
                return GameEventResult::FAILURE;
            }
            // Introduce a chance for fumble
            if (fumbleRate > 0.0 && rng() % 100 < fumbleRate * 100) {
                return GameEventResult::FUMBLE;
            }
            return GameEventResult::FAILURE;
        }
    } else {
        // Draw from the deck
        Logger::log("Using a deck of cards to generate the result.", Logger::LogType::INFO);
        int drawResult = decks[randomIndex - dice.size() - coins.size()].draw(criticalRate, failureRate, fumbleRate);
        if (drawResult > 0) {
            return GameEventResult::SUCCESS;
        } else if (drawResult < 0) {
            // Introduce a chance for failure
            if (failureRate > 0.0 && rng() % 100 < failureRate * 100) {
                return GameEventResult::FAILURE;
            }
            // Introduce a chance for fumble
            if (fumbleRate > 0.0 && rng() % 100 < fumbleRate * 100) {
                return GameEventResult::FUMBLE;
            }
            return GameEventResult::FAILURE;
        } else {
            // Introduce a chance for fumble
            if (fumbleRate > 0.0 && rng() % 100 < fumbleRate * 100) {
                return GameEventResult::FUMBLE;
            }
            // Introduce a chance for failure
            if (failureRate > 0.0 && rng() % 100 < failureRate * 100) {
                return GameEventResult::FAILURE;
            }
            return GameEventResult::FAILURE;
        }
    }
}




