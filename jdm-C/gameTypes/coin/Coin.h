#ifndef JDR_COIN_H
#define JDR_COIN_H
#include "../../interfaces/RollingInterface.h"
#include "../../tools/logger/Logger.h"

class Coin: public RollingInterface, protected Logger {
private:
    int draws;
    int result;
public:
    Coin(int draws = 5, int result = 0);
    void setResult(int result);
    int getResult();
    int tossCoin(int draw);
    void rolling(float chance);
    void showResult();
};
#endif //JDR_COIN_H
