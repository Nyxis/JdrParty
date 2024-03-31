#include "GameCard.h"
#include <iostream>
#include "../../tools/randomGenerator/RandomGenerator.h"
#include "../../tools/cardsAdapter/CardsAdapter.h"


void GameCard::setCardType() {
    this->cardType = RandomGenerator::getRandom(2,4);
}
int GameCard::getCardType() {
    return this->cardType;
}
void GameCard::setCardNumber() {
    this->cardNumber = RandomGenerator::getRandom(1,13);
}
int GameCard::getCardNumber() {
    return this->cardNumber;
}
void GameCard::rolling(float chance) {
    this->setCardType();
    this->setCardNumber();
}
void GameCard::showResult() {
    std::string type = CardsAdapter::getCardType(this->cardType);
    std::string card = CardsAdapter::getCard(this->cardNumber);
    std::cout << "-----We have " << type + " " + card << "-----" << std::endl;
}
