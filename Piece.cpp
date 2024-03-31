#include "Piece.h"
#include <cstdlib>

Piece::Piece(int nombreLances)
{
    this->nombreLances = nombreLances;
}

std::string Piece::genererResultat()
{
    return lancerPiece(nombreLances) ? "pile" : "face";
}

std::string Piece::getNomMateriel()
{
    return "Piece";
}

bool Piece::lancerPiece(int nombreLances)
{
    if (nombreLances == 1)
    {
        return rand() % 2 == 0;
    }
    else
    {
        return lancerPiece(nombreLances - 1) && (rand() % 2 == 0);
    }
}