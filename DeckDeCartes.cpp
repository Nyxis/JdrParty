#include "DeckDeCartes.h"
#include <cstdlib>

DeckDeCartes::DeckDeCartes(int nombreCouleurs, int nombreValeurs)
{
    this->nombreCouleurs = nombreCouleurs;
    this->nombreValeurs = nombreValeurs;
}

std::string DeckDeCartes::genererResultat()
{
    int couleur = rand() % nombreCouleurs + 1;
    int valeur = rand() % nombreValeurs + 1;
    return std::to_string(couleur) + " " + std::to_string(valeur);
}

std::string DeckDeCartes::getNomMateriel()
{
    return "Deck de cartes";
}