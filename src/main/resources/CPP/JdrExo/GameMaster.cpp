//
// Created by jux on 3/21/24.
//

#include "GameMaster.hpp"

#include <iomanip>
#include "Coin.hpp"
#include "Deck.hpp"
#include "Dice.hpp"
#include "ResultatTirage.hpp"
#include <sstream>

#include "Logger.hpp"
#include "RandomNumberGenerator.hpp"
using RNG = RandomNumberGenerator;



std::string GameMaster::pleaseGiveMeACrit(float critRate, float successRate, float fumbleRate)
{
    int randNum = RNG::generate(1, 7);
    int score;
    std::ostringstream oss;
    oss<<std::setprecision(2)<<
                        "Taux critique : "<<((critRate-1)*100)<<"%\n"
                        "Taux Echec : "<<((successRate-1)*100)<<"%\n"
                       "Taux Fumble : "<<((1 - fumbleRate)*100)<<"%"<<std::endl;
    std::string rateInfos = oss.str();
    switch (randNum)
    {
    case 1:
    case 2:
        {
            Coin coin(RNG::generate(1, 5));
            score = (coin.tirage() * 50) * successRate * critRate * fumbleRate;
            log(rateInfos);

            std::ostringstream oss;
            oss << "score =  " << score << std::endl;
            std::string message = oss.str();
            log(message);
;


            return ResultatTirage::resultat(score);
        }
    case 3:
        {
            Deck weirdDeck(3);
            score = weirdDeck.tirage() * successRate * critRate * fumbleRate;
            log(rateInfos);
;

            std::ostringstream oss;
            oss << "score =  " << score << std::endl;
            std::string message = oss.str();
            log(message);
;

            return ResultatTirage::resultat(score);
        }
    case 4:
        {
            Deck regularDeck(4);
            score = regularDeck.tirage() * successRate * critRate * fumbleRate;
            log(rateInfos);
;

            std::ostringstream oss;
            oss << "score =  " << score << std::endl;
            std::string message = oss.str();
            log(message);
;

            return ResultatTirage::resultat(score);
        }
    case 5:
        {
            Dice smallDice(6);
            score = smallDice.tirage() * successRate * critRate * fumbleRate;
            log(rateInfos);
;

            std::ostringstream oss;
            oss << "score =  " << score << std::endl;
            std::string message = oss.str();
            log(message);
;

            return ResultatTirage::resultat(score);
        }
    case 6:
        {
            Dice midDice(10);
            score = midDice.tirage() * successRate * critRate * fumbleRate;
            log(rateInfos);
;

            std::ostringstream oss;
            oss << "score =  " << score << std::endl;
            std::string message = oss.str();
            log(message);
;

            return ResultatTirage::resultat(score);
        }
    case 7:
        {
            Dice bigDice(20);
            score = bigDice.tirage() * successRate * critRate * fumbleRate;
            log(rateInfos);
;
            
            std::ostringstream oss;
            oss << "score =  " << score << std::endl;
            std::string message = oss.str();
            log(message);
;

            return ResultatTirage::resultat(score);
        }
    default:
        return "Le maitre du jeu a fait tomber son item dans sa pinte de bière. La partie est terminée";
    }
}



