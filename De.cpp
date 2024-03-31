#include "De.h"
#include <cstdlib>

De::De(std::vector<int> faces, int nombreLances)
{
    this->faces = faces;
    this->nombreLances = nombreLances;
}

De::De(int nombreFaces, int nombreLances)
{
    for (int i = 1; i <= nombreFaces; i++)
    {
        this->faces.push_back(i);
    }
    this->nombreLances = nombreLances;
}

std::string De::genererResultat()
{
    int resultat = 0;
    for (int i = 0; i < nombreLances; i++)
    {
        int index = rand() % faces.size();
        resultat += faces[index];
    }
    return std::to_string(resultat);
}

std::string De::getNomMateriel()
{
    return "De";
}

int De::getNombreLances()
{
    return nombreLances;
}