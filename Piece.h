#include "TirageAleatoire.h"

class Piece : public TirageAleatoire
{
private:
    int nombreLances;

public:
    Piece(int nombreLances);
    std::string genererResultat() override;
    std::string getNomMateriel() override;

private:
    bool lancerPiece(int nombreLances);
};