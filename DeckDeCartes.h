#include "TirageAleatoire.h"

class DeckDeCartes : public TirageAleatoire
{
private:
    int nombreCouleurs;
    int nombreValeurs;

public:
    DeckDeCartes(int nombreCouleurs, int nombreValeurs);
    std::string genererResultat() override;
    std::string getNomMateriel() override;
};