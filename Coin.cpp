#include "Coin.h"
#include <cstdlib>
#include <string>





Coin::Coin(int pile, int face) {


};


std::string Coin::flip(){
    int result = (rand() % 2);
    if ( result == 1){
         return "Vous lancez une piece elle tombe sur Pile ";
    }else{
         return "Vous lancez une piece elle tombe sur  Face ";
    }

}