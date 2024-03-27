#include <iostream>
#include "GameMaster.hpp"
#include "Logger.hpp"

#include "RandomNumberGenerator.hpp"
using RNG = RandomNumberGenerator;

int main(int argc, char* argv[])
{
    float critRate = atof(argv[1]);
    float failRate = atof(argv[2]);
    float fumbleRate = atof(argv[3]);

if (
    typeid(critRate) != typeid(float)   ||
    typeid(failRate) != typeid(float)   ||
    typeid(fumbleRate) != typeid(float))   {

        std::cout<<"NOTHING TO DO WITH THAT, MASTER !!"<<std::endl;
        exit(EXIT_FAILURE);
    }


    Logger::log(GameMaster::pleaseGiveMeACrit(critRate, failRate, fumbleRate));
}
