//
// Created by admin on 25/03/2024.
//

#ifndef TP_CPP_LOGGER_H
#define TP_CPP_LOGGER_H
#include <string>
#include "LoggerOutAdapter.h"
class Logger : public LoggerOutAdapter{
private:
    static std::string method;
public:
    static void Log(std::string message);
};


#endif //TP_CPP_LOGGER_H
