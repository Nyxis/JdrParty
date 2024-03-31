#ifndef JDR_GAMECARD_H
#define JDR_GAMECARD_H
#include <iostream>
#include "../../interfaces/RollingInterface.h"
#include "../../tools/logger/Logger.h"

class GameCard: protected Logger{
private:
    int cardType;
    int cardNumber;
public:
    void rolling(float chance);
    void setCardType();
    int getCardType();
    void setCardNumber();
    int getCardNumber();
    void showResult();
};
#endif //JDR_GAMECARD_H
