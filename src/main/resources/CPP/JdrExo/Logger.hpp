//
// Created by jux on 3/22/24.
//

#ifndef LOGGER_H
#define LOGGER_H


#include "CliLogger.hpp"
#include "GameLogger.h"


class Logger : public CliLogger, GameLogger
{
public:
    template <typename T>
    static void log(T message)
    {
        typeid(message) == typeid(std::string)
            ? cliOutput(message)
            // : typeid(message) == typeid(int)
            // ? gameOutput(message)
            : incorrectOutput();
    }

private:
    static void incorrectOutput();
};


#endif //LOGGER_H
