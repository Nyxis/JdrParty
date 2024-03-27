//
// Created by admin on 22/03/2024.
//

#ifndef TP_CPP_RANDOMNUMBERGENERATOR_H
#define TP_CPP_RANDOMNUMBERGENERATOR_H
#include <random>

class RandomNumberGenerator
{
public:
    static int generate(int min, int max)
    {
        static std::mt19937 gen(std::random_device{}());
        std::uniform_int_distribution<> dist(min, max);
        return dist(gen);
    }
};

#endif //TP_CPP_RANDOMNUMBERGENERATOR_H
