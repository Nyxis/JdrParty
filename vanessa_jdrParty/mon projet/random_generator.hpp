#ifndef RANDOM_GENERATOR_HPP
#define RANDOM_GENERATOR_HPP

#include "random_result.hpp"

class RandomGenerator {
public:
    virtual RandomResult generate() const = 0;
};

#endif
