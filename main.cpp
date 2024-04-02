#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "Coin.h"
#include "Deck.h"
#include "Dice.h"
#include "GameMaster.h"
using namespace std;



int main() {
    system("chcp 65001");
    srand(time(0)); // Initialize the random number generator

    int numberOfCards = 5;
    for (int i = 0; i < numberOfCards; ++i) {
        cout << "vous avez tirez le  " << Deck::randomCard() << endl;
    }

    cout << "vous lancez un dé, il tombe sur " << Dice::randomDice() << endl;
    cout << "" <<   Coin::flip() << endl;
    cout << "Le Mj joue" <<    Maitre::randomMj() << endl;


  return 0;



}