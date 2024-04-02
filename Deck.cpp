#include "Deck.h"
#include <cstdlib>
#include <string>



Deck::Deck(int card) {


};

std::string sign[] = {"Carreau","Pique","Coeur","Trefle"};

std::string value[] = {"Deux ","Trois ","Quatre ","Cinq ","Six ","Sept ","Huit ","Neuf ","Dix ","Vallet ","Reine ","Roi ","As "};

std::string Deck::randomCard(){


    int cardValue = (rand() % 13);
    int cardSign = (rand() % 4);

    std::string card = value[cardValue] + "De " + sign[cardSign];
    return card;

}//
// Created by chels on 26/03/2024.
//
