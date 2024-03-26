//
// Created by admin on 21/03/2024.
//
#include "Tirage.h"
#include "ObjetAleatoire.h"
#include "RandomNumberGenerator.h"
#include "Logger.h"
#include <iostream>

Tirage::Tirage(float suc, float crit, float ech, De obj) {
    this->succes = suc;
    this->critique = crit;
    this->echec = ech;
    this->nom = obj.getName();
    this->resultat=obj.roll();
    Logger::Log("Succes2: "+to_string(this->getSucces())+"   Crit2: "+to_string(this->getCritique())+"   Echec2: "+to_string(this->getEchec()));

}
Tirage::Tirage(float suc, float crit, float ech, Piece obj) {
    this->succes = suc;
    this->critique = crit;
    this->echec = ech;
    this->nom = obj.getName();
    int r = RandomNumberGenerator::generate(1, 5);
    this->resultat=obj.roll(r);
    Logger::Log("Succes2: "+to_string(this->getSucces())+"   Crit2: "+to_string(this->getCritique())+"   Echec2: "+to_string(this->getEchec()));

}
Tirage::Tirage(float suc, float crit, float ech, Deck obj) {
    this->succes = suc;
    this->critique = crit;
    this->echec = ech;
    this->nom = obj.getName();
    this->resultat=obj.roll();
    Logger::Log("Succes2: "+to_string(this->getSucces())+"   Crit2: "+to_string(this->getCritique())+"   Echec2: "+to_string(this->getEchec()));

}
Tirage::Tirage(){
    this->succes = 0;
    this->critique = 0;
    this->echec = 0;
    this->resultat=0;
}
float Tirage::getResultat(){
    return this->resultat;
}
string Tirage::getResultatString() {
    if(this->resultat <= this->echec){
        this->resultatState = 1;
        return "Echec critique !";
    }
    else {
        if(this->resultat < this->succes){
            this->resultatState = 2;
            return "Echec !";
        }
        else {
            if(this->resultat < this->critique){
                this->resultatState = 3;
                return "Réussite !";
            }
            else {
                this->resultatState = 4;
                return "Réussite critique !";
            }
        }
    }
}
float Tirage::getSucces(){
    return this->succes;
}
float Tirage::getCritique(){
    return this->critique;
}
float Tirage::getEchec(){
    return this->echec;
}
std::string Tirage::getName(){
    return this->nom;
}
int Tirage::getResultatState(){
    return this->resultatState;
}