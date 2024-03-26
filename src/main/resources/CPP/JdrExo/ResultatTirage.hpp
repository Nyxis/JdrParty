//
// Created by jux on 3/21/24.
//

#ifndef RESULTATTIRAGE_H
#define RESULTATTIRAGE_H
#include <string>

enum class ResultatConst {
    Reussite,
    Echec,
    ReussiteCritique,
    Fumble
};
class ResultatTirage : public Logger
{
public:
    std::string static resultat(int score){

            return score >= 90
                   ? enumToString(ResultatConst::ReussiteCritique)
                   : score >= 40
                   ? enumToString(ResultatConst::Reussite)
                   : score >= 20
                   ? enumToString(ResultatConst::Echec)
                   : enumToString(ResultatConst::Fumble);
    }

    static std::string  enumToString(ResultatConst resultatConst) {

        switch (resultatConst) {
        case ResultatConst::Reussite:
            return "Reussite";
        case ResultatConst::Echec:
            return "Echec";
        case ResultatConst::ReussiteCritique:
            return "Reussite Critique";
        case ResultatConst::Fumble:
            return "Fumble";
        default:
            return "le maitre du jeu est malheureusement indisponible pour donner le verdict. Déso !";
        }

    }
};
#endif //RESULTATTIRAGE_H
