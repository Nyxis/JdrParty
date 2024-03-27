cmake_minimum_required(VERSION 3.28)
project(JdrExo)

set(CMAKE_CXX_STANDARD 17)

add_executable(JdrExo main.cpp
        ResultatTirage.hpp
        TirageAction.cpp
        TirageAction.hpp
        Dice.cpp
        Dice.hpp
        Coin.cpp
        Coin.hpp
        Deck.cpp
        Deck.hpp
        GameMaster.cpp
        GameMaster.hpp
        RandomNumberGenerator.hpp
        Logger.hpp
        CliLogger.hpp
        Logger.cpp
        GameLogger.h
)
