//
// Created by jux on 3/21/24.
//

#ifndef RANDOMNUMBERGENERATOR_H
#define RANDOMNUMBERGENERATOR_H
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

    static float generateFloat(float min, float max)
    {
        static std::mt19937 gen(std::random_device{}());
        std::uniform_real_distribution<float> dist(min, max);
        return dist(gen);
    }
};

#endif //RANDOMNUMBERGENERATOR_H
