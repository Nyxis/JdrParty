#include "RandomGenerator.h"
#include <iostream>
#include <random>
using namespace std;

int RandomGenerator::getRandom(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());

    // Define the distribution
    std::uniform_int_distribution<> dis(min, max);

    int random = dis(gen);
    return random;
}