//
// Created by vitsi on 26/03/2024.
//

#ifndef JDRPARTY_LOGGER_H
#define JDRPARTY_LOGGER_H

#include <string>


class Logger {
public:
    enum class LogType { INFO, WARNING, ERROR };
    static void log(const std::string& message, LogType type);
private:
    static std::string logTypeToString(LogType type);
};


#endif //JDRPARTY_LOGGER_H
