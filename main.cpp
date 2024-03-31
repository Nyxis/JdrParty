#include <iostream>
#include <vector>
#include "RandomDrawResult.h"
#include "RandomDraw.h"
#include "Die.h"
#include "Coin.h"
#include "CardDeck.h"
#include "GameMaster.h"


int main() {

    std::vector<RandomDrawResult> results = {
            RandomDrawResult(50, 10, 5),
            RandomDrawResult(30, 20, 10),
            RandomDrawResult(80, 5, 2)
    };

    RandomDraw draw(results);
    for (int i = 0; i < 10; i++) {
        RandomDrawResult::ResultType result = draw.draw();

        switch (result) {
            case RandomDrawResult::ResultType::SUCCESS:
                std::cout << "Réussite !" << std::endl;
                break;
            case RandomDrawResult::ResultType::FAILURE:
                std::cout << "Echec !" << std::endl;
                break;
            case RandomDrawResult::ResultType::CRITICAL_SUCCESS:
                std::cout << "Réussite critique !" << std::endl;
                break;
            case RandomDrawResult::ResultType::FUMBLE:
                std::cout << "Fumble !" << std::endl;
                break;
        }

        GameMaster gm;
        for (int i = 0; i < 5; i++) {
            int successRate = 0;
            int criticalRate = 100;
            int fumbleRate = 0;
            RandomDrawResult::ResultType gmResult = gm.pleaseGiveMeACrit(successRate, criticalRate, fumbleRate);

            switch (gmResult) {
                case RandomDrawResult::ResultType::SUCCESS:
                    std::cout << "Réussite !" << std::endl;
                    break;
                case RandomDrawResult::ResultType::FAILURE:
                    std::cout << "Echec !" << std::endl;
                    break;
                case RandomDrawResult::ResultType::CRITICAL_SUCCESS:
                    std::cout << "Réussite critique !" << std::endl;
                    break;
                case RandomDrawResult::ResultType::FUMBLE:
                    std::cout << "Fumble !" << std::endl;
                    break;
            }
        }

        return 0;
    }