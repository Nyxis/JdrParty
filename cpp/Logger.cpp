//
// Created by admin on 25/03/2024.
//

#include "Logger.h"
#include "LoggerOutAdapter.h"
#include <string>

void Logger::Log(std::string message){
    LoggerOutAdapter::Display(message, "console");
}
