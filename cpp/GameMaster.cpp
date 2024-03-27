//
// Created by admin on 21/03/2024.
//

#include "GameMaster.h"
#include "Tirage.h"
#include "RandomNumberGenerator.h"
#include "Logger.h"
#include<list>
#include<string>
#include <iostream>

GameMaster::GameMaster(list<int> listeFacesDes, list<int> listeNbFaces, int nbPiece, list<int> nbCouleurs, list<int> nbValeurs){
    this->listeDes = {};
    this->listeDecks = {};
    this->listePieces = {};
    this->tyrage = Tirage();
    auto it = listeNbFaces.begin();
    auto itef = listeFacesDes.begin();
    list<int> lst = {};
    int cnt = 0;
    //int cntNF = 1;

    lst.push_back(*itef);
    for(int i = 1; i <= listeFacesDes.size(); i++) {
        advance(itef, 1);
        if (i < *it + cnt) {
            lst.push_back(*itef);
        } else {
            if (i == *it + cnt) {
                this->listeDes.push_back(De(lst));
                lst = {};
                cnt += *it;
                //cntNF++;
                advance(it, 1);
                if(i != listeFacesDes.size()){
                    lst.push_back(*itef);
                }
            }
        }
    }
    //this->listeDes.push_back(De(lst));
    this->nbDes = listeNbFaces.size();
    cnt = 0;
    for(int i=0; i< nbPiece; i++)
    {
        this->listePieces.push_back(Piece());
        cnt++;
    }
    this->nbPieces = cnt;
    cnt=0;
    it = nbCouleurs.begin();
    itef = nbValeurs.begin();
    this->listeDecks.push_back(Deck(*it, *itef));
    cnt++;
    for(int i=1; i < nbCouleurs.size(); i++)
    {
        advance(it, 1);
        advance(itef, 1);
        this->listeDecks.push_back(Deck(*it, *itef));
        cnt++;
    }
    this->nbDecks = cnt;
}
string GameMaster::pleaseGiveMeACrit(float fumble, float succes, float critique){

    int max = (this->nbPieces+this->nbDes+this->nbDecks-1);
    int r = RandomNumberGenerator::generate(0, max);
    if(r < this->nbDes)
    {
        auto it = this->listeDes.begin();
        advance(it, r);
        this->tyrage = Tirage(fumble, succes, critique,  *it);
    }
    else
    {
        if(r < (this->nbDes + this->nbPieces))
        {
            auto it = this->listePieces.begin();
            r -= this->nbDes;
            advance(it, r);
            this->tyrage = Tirage(fumble, succes, critique, *it);
        }
        else
        {
            auto it = this->listeDecks.begin();
            r -= this->nbDes + this->nbPieces;
            advance(it, r);
            this->tyrage = Tirage(fumble, succes, critique, *it);
        }
    }

    return this->tyrage.getResultatString();
}
string GameMaster::getObjetNom(){
    return this->tyrage.getName();
}
float GameMaster::getResultat() {
    return this->tyrage.getResultat();
}
int GameMaster::getResultatState() {
    return this->tyrage.getResultatState();
}
float GameMaster::getSuccess(){
    return this->tyrage.getSucces();
}
float GameMaster::getCritique(){
    return this->tyrage.getCritique();
}
float GameMaster::getEchec(){
    return this->tyrage.getEchec();
}