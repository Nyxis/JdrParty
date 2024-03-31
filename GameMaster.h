#include "TirageAleatoire.h"
#include <vector>
#include <string>

class GameMaster
{
private:
    std::vector<TirageAleatoire *> materiel;

public:
    GameMaster();
    ~GameMaster();
    std::pair<std::string, std::string> pleaseGiveMeACrit(int tauxReussite, int tauxCritique, int tauxFumble);
};