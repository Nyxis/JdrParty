#include "../../tools/randomGenerator/RandomGenerator.h"
#include "Coin.h"
#include <iostream>
using namespace std;

Coin::Coin(int draws, int result){
    //constructor with params by default from draws 5 and result 0
    this->draws = draws;
    this->result = result;
};
void Coin::setResult(int result){
    this->result = result;
}
int Coin::getResult(){
    return this->result;
}
int Coin::tossCoin(int draw) {
    if (draw == 0){
        this->setResult(1);
        return 1;
    }
    int result = (RandomGenerator::getRandom(0,1)) % 2;
    if (result == 0) {
        this->setResult(0);
        return 0;
    }
    return this->tossCoin(draw - 1);
}
void Coin::rolling(float chance) {
    setResult(this->tossCoin(this->draws) * chance);
}

void Coin::showResult() {
    std::string str = (this->getResult() == 0) ? "heads" : "tails";
    std::cout << "-----We have " << str << "-----" << std::endl;
}
