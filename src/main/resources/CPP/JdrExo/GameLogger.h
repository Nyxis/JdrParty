//
// Created by jux on 3/26/24.
//

#ifndef GAMELOGGER_H
#define GAMELOGGER_H

#include <iostream>
class GameLogger {

protected:

    static void gameOutput(const int &message)
    {
        message == 0 ? std::cout<<"démarrage de la partie"<<std::endl
            :message == 1 ? std::cout<<"Fin de la partie"<<std::endl
                : std::cout<<"do sthg"<<std::endl;


    };

};
#endif //GAMELOGGER_H
