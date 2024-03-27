//
// Created by admin on 21/03/2024.
//

#include "Piece.h"
#include "RandomNumberGenerator.h"
#include "Logger.h"
#include <cstdlib>
Piece::Piece(){
    this->valeurMin = 0;
    this->valeurMax = 1;
    this->nom = "une pièce";
}
float Piece::roll(int n){
    int r;
    for(int i = 0; i < n; i++){
        r = RandomNumberGenerator::generate(this->valeurMin, this->valeurMax);
        if(r == 0) {
            if(i!=0){
                Logger::Log("roll failed on #"+to_string(i+1)+"   rolls nb : "+to_string(n)+"   get : "+to_string(static_cast<float>(i)/static_cast<float>(n)));
                float flo = static_cast<float>(i)/static_cast<float>(n);
                return flo;
            }
            return 0;
        }
    }
    return 1;
}
string Piece::getName(){
    return this->nom;
}