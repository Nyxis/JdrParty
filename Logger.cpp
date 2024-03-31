#include "Logger.h"

Logger *Logger::instance = nullptr;

Logger *Logger::getInstance()
{
    if (!instance)
    {
        instance = new Logger();
    }
    return instance;
}

void Logger::log(const std::string &message)
{
    std::cout << message << std::endl;
}