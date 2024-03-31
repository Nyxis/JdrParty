#include "CardsAdapter.h"
#include <iostream>

std::string CardsAdapter::cardsAdapter(int cardType, int cardNumber) {
  return CardsAdapter::getCardType(cardType) + " " + CardsAdapter::getCard(cardNumber);
}

std::string CardsAdapter::getCardType(int type){
    switch (type) {
        case 1:
            return "Clubs";
        case 2:
            return "Diamonds";
        case 3:
            return "Hearts";
        case 4:
            return "Spades";
    }
}
std::string CardsAdapter::getCard(int card) {
    switch (card) {
        case 11:
            return "Jack";
        case 12:
            return "Queen";
        case 13:
            return "King";
        case 1:
            return "A";
        default:
            return std::to_string(card);
    }
}