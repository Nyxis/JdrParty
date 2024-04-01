//
// Created by vitsi on 26/03/2024.
//

#include "Logger.h"
#include <iostream>
#include <cmath>

void Logger::log(const std::string& message, LogType type) {
    std::cout << "[" << logTypeToString(type) << "] " << message << std::endl;
}

std::string Logger::logTypeToString(LogType type) {
    switch (type) {
        case LogType::INFO: return "INFO";
        case LogType::WARNING: return "WARNING";
        case LogType::ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}
