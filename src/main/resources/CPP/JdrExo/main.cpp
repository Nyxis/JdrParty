#include <iostream>
#include "GameMaster.hpp"
#include "Logger.hpp"

#include "RandomNumberGenerator.hpp"
using RNG = RandomNumberGenerator;

int main(int argc, char* argv[])
{
    float critRate, successRate, fumbleRate;

    if (*argv[1] == 'a')
    {
        critRate = 1.1;
        successRate = 1.45;
        fumbleRate = 0.95;
    }
    else if (*argv[1] == 'e')
    {
        critRate = 1.2;
        successRate = 1.25;
        fumbleRate = 0.85;
    }
    else if (*argv[1] == 'p')
    {
        critRate = 1;
        successRate = 1.6;
        fumbleRate = 1;
    }
    else if (*argv[1] == 'f')
    {
        critRate = 1.5;
        successRate = 1;
        fumbleRate = 0.5;
    }
    else
    {
        std::cout<<"NOTHING TO DO"<<std::endl;
        exit(EXIT_FAILURE);
    }


    Logger::log(GameMaster::pleaseGiveMeACrit(critRate, successRate, fumbleRate));
}
