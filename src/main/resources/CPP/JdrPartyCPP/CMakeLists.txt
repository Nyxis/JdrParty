cmake_minimum_required(VERSION 3.26)
project(JdrParty)

set(CMAKE_CXX_STANDARD 17)

add_executable(JdrParty main.cpp
        Dice.h
        GameEventResult.h
        GameEventResult.cpp
        Coin.h
        Coin.cpp
        Deck.h
        Dice.cpp
        GameMaster.h
        GameMaster.cpp
        Deck.cpp
        Logger.cpp)
