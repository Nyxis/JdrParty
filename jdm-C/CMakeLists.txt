cmake_minimum_required(VERSION 3.27)
project(jdr)

set(CMAKE_CXX_STANDARD 23)

add_executable(jdr main.cpp
        tools/randomGenerator/randomGenerator.cpp
        tools/randomGenerator/randomGenerator.h
        gameTypes/dice/Dice.cpp
        gameTypes/dice/Dice.h
        interfaces/RollingInterface.cpp
        interfaces/RollingInterface.h
        gameTypes/coin/Coin.cpp
        gameTypes/coin/Coin.h
        gameTypes/gameCard/GameCard.cpp
        gameTypes/gameCard/GameCard.h
        gameMaster/GameMaster.cpp
        gameMaster/GameMaster.h
        tools/logger/Logger.cpp
        tools/logger/Logger.h
        tools/cardsAdapter/CardsAdapter.cpp
        tools/cardsAdapter/CardsAdapter.h)
