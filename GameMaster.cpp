
#include "GameMaster.h"


#include "GameMatser.h"
#include <stdexcept>
#include <cstdlib>

GameMaster::GameMaster() {
    m_dices.push_back(Die(6));
    m_dices.push_back(Die(10));
    m_dices.push_back(Die(20));

    m_coins.push_back(Coin(1));
    m_coins.push_back(Coin(2));

    m_cardDecks.push_back(CardDeck(3, 18));
    m_cardDecks.push_back(CardDeck(4, 13));
}

int GameMaster::pleaseGiveMeACrit(int successRate, int criticalRate, int fumbleRate) {
    if (successRate < 0 || criticalRate < 0 || fumbleRate < 0 ||
        successRate + criticalRate + fumbleRate != 100) {
        throw std::invalid_argument("Les taux de réussite, de critique et de fumble doivent être compris entre 0 et 100 et leur somme doit être égale à 100.");
    }

    int randomIndex = std::rand() % (m_dices.size() + m_coins.size() + m_cardDecks.size());
    int roll;

    if (randomIndex < m_dices.size()) {
        roll = m_dices[randomIndex].roll(); // Variable roll déplacée pour une portée plus large
    } else if (randomIndex < m_dices.size() + m_coins.size()) {
        int flip = m_coins[randomIndex - m_dices.size()].flip();
        return flip == 0 ? FUMBLE : (std::rand() % 100) + 1 <= criticalRate ? CRITICAL_SUCCESS : SUCCESS;
    } else {
        int draw = m_cardDecks[randomIndex - m_dices.size() - m_coins.size()].draw();
        if (draw <= fumbleRate) {
            return FUMBLE;
        } else if (draw <= fumbleRate + criticalRate) {
            return CRITICAL_SUCCESS;
        } else {
            return SUCCESS;
        }
    }

    if (roll <= fumbleRate) {
        return FUMBLE;
    } else if (roll <= fumbleRate + criticalRate) {
        return CRITICAL_SUCCESS;
    } else {
        return SUCCESS;
    }
}