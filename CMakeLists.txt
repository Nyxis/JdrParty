cmake_minimum_required(VERSION 3.27)
project(Mmadi_mourtadhoi)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Mmadi_mourtadhoi
        RandomDrawResult.cpp
        RandomDrawResult.h
        CardDeck.h
        CardDeck.h
        CardDeck.cpp
        Coin.h
        Coin.cpp)
