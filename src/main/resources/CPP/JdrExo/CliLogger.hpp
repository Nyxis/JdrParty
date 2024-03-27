//
// Created by jux on 3/25/24.
//

#ifndef CLILOGGER_H
#define CLILOGGER_H
#include <iostream>
#include <string>

class CliLogger {

protected:

    static void cliOutput(const std::string &message)
    {
        std::cout<<message<<std::endl;
    };

};

#endif //CLILOGGER_H
