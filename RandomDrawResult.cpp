
#include "RandomDrawResult.h"
RandomDrawResult::RandomDrawResult(int successRate, int criticalRate, int fumbleRate) :
        m_successRate(successRate), m_criticalRate(criticalRate), m_fumbleRate(fumbleRate) {

    if (successRate < 0 || criticalRate < 0 || fumbleRate < 0 ||
        successRate + criticalRate + fumbleRate != 100) {
        throw std::invalid_argument("Les taux de réussite, de critique et de fumble doit être compris entre 0 et 100 et la somme = 100.");
    }
}

RandomDrawResult::ResultType RandomDrawResult::draw() {

    std::srand(std::time(0));


    int randomValue = std::rand() % 100;


    if (randomValue < m_fumbleRate) {
        return ResultType::FUMBLE;
    } else if (randomValue < m_fumbleRate + m_criticalRate) {
        return ResultType::CRITICAL_SUCCESS;
    } else if (randomValue < m_fumbleRate + m_criticalRate + m_successRate) {
        return ResultType::SUCCESS;
    } else {
        return ResultType::FAILURE;
    }
}