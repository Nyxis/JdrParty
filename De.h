#include "TirageAleatoire.h"
#include <vector>

class De : public TirageAleatoire
{
private:
    std::vector<int> faces;
    int nombreLances;

public:
    De(std::vector<int> faces, int nombreLances);
    De(int nombreFaces, int nombreLances);
    std::string genererResultat() override;
    std::string getNomMateriel() override;
    int getNombreLances();
};