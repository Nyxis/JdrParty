//
// Created by jux on 3/21/24.
//

#ifndef GAMEMASTER_H
#define GAMEMASTER_H
#include <string>

#include "Logger.hpp"

class GameMaster : protected Logger
{
public:
    static std::string pleaseGiveMeACrit(float critRate, float successRate, float fumbleRate) ;
};


#endif //GAMEMASTER_H
