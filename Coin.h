#ifndef COIN_H
#define COIN_H
#include <cstdlib>
#include <string>

class Coin
{
public:


    Coin(int pile, int face);



    static std::string flip();
};
#endif
