#include "GameMaster.h"
#include "Logger.h"
#include "De.h"
#include "DeckDeCartes.h"
#include "Piece.h"
#include <cstdlib>
#include <vector>
#include <string>

GameMaster::GameMaster()
{
    materiel.push_back(new De(6, 1));
    materiel.push_back(new DeckDeCartes(3, 18));
    materiel.push_back(new DeckDeCartes(4, 13));
    materiel.push_back(new Piece(1));
    materiel.push_back(new Piece(1));
}

GameMaster::~GameMaster()
{
    for (TirageAleatoire *obj : materiel)
    {
        delete obj;
    }
}

std::pair<std::string, std::string> GameMaster::pleaseGiveMeACrit(int tauxReussite, int tauxCritique, int tauxFumble)
{
    // Votre code ici
}