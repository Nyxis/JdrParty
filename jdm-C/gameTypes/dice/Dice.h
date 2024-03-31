#ifndef JDR_DICE_H
#define JDR_DICE_H
#include "../../interfaces/RollingInterface.h"
#include "../../tools/logger/Logger.h"

class Dice: public RollingInterface, protected Logger{
private:
    //First dice
    int firstDice;
    //Second dice
    int secondDice;
    // Numbers for make a rang of dices
    int maxFace;
    int minFace;
public:
    Dice(int min = 1, int max = 6);
    void setFirstDice(float chance);
    void setSecondDice(float chance);
    // rolling fn from interface
    void rolling(float chance);
    void showResult();
};


#endif //JDR_DICE_H
