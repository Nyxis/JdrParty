//
// Created by admin on 21/03/2024.
//

#ifndef TP_CPP_GAMEMASTER_H
#define TP_CPP_GAMEMASTER_H
#include <string>
#include<list>
#include "Tirage.h"
#include "De.h"
#include "Deck.h"
#include "Piece.h"
using namespace std;
class GameMaster {
    list<De> listeDes;
    list<Piece> listePieces;
    list<Deck> listeDecks;
    int nbDes, nbPieces, nbDecks;
    Tirage tyrage;

public:
    GameMaster(list<int> listeFacesDes, list<int> listeNbDes, int nbPiece, list<int> nbCouleurs, list<int> nbValeurs);
    string pleaseGiveMeACrit(float fumble, float succes, float critique);
    string getObjetNom();
    float getResultat();
    float getSuccess();
    float getCritique();
    float getEchec();
    int getResultatState();
};


#endif //TP_CPP_GAMEMASTER_H
