//
// Created by admin on 21/03/2024.
//

#ifndef TP_CPP_DE_H
#define TP_CPP_DE_H
#include<list>
#include "ObjetAleatoire.h"
#include <string>
using namespace std;
class De {
    int nombreFaces;
    list<int> listeFaces;
    int valeurMin;
    int valeurMax;
    string nom;
public:
    De(int nbFace);
    De(list<int> listFace);
    float roll();
    string getName();
};


#endif //TP_CPP_DE_H
