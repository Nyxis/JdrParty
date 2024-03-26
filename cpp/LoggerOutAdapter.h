//
// Created by admin on 25/03/2024.
//

#ifndef TP_CPP_LOGGEROUTADAPTER_H
#define TP_CPP_LOGGEROUTADAPTER_H
#include "StdOutLogger.h"
#include "FileOutLogger.h"
#include <string>
class LoggerOutAdapter : public StdOutLogger, public FileOutLogger{
public:
    static void Display(std::string message, std::string method);
};


#endif //TP_CPP_LOGGEROUTADAPTER_H
