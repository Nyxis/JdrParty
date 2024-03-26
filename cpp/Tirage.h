//
// Created by admin on 21/03/2024.
//

#ifndef TP_CPP_TIRAGE_H
#define TP_CPP_TIRAGE_H
#include <string>
#include "De.h"
#include "Deck.h"
#include "Piece.h"
using namespace std;
class Tirage
{
    string nom;
    int resultatState;
    float succes, critique, echec, resultat;

public:
    Tirage(float suc, float crit, float ech, De obj);
    Tirage(float suc, float crit, float ech, Piece obj);
    Tirage(float suc, float crit, float ech, Deck obj);
    Tirage();
    float getResultat();
    float getSucces();
    float getCritique();
    float getEchec();
    string getResultatString();
    int getResultatState();
    string getName();

};

#endif //TP_CPP_TIRAGE_H
