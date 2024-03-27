//
// Created by admin on 21/03/2024.
//

#include "Deck.h"
#include "RandomNumberGenerator.h"
#include "Logger.h"
#include <iostream>
#include <cstdlib>
Deck::Deck(int couleurs, int valeurs) {
    this->nbCouleurs = couleurs;
    this->nbValeurs = valeurs;
    this->valeurMin = 1;
    this->valeurMax = this->nbCouleurs * this->nbValeurs;
    this->nom = "un deck";
}
float Deck::roll(){
    int r = RandomNumberGenerator::generate(this->valeurMin, this->valeurMax);
    float res = static_cast<float>(r)/static_cast<float>(this->valeurMax);
    Logger::Log("Min : "+to_string(this->valeurMin)+"   Max : "+to_string(this->valeurMax)+"   Res : "+to_string(r)+"   Res 2 :"+to_string(res));
    return res;
}
string Deck::getName(){
    return this->nom;
}