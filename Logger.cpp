
#include "Logger.h"


class Logger {
public:
    enum class Level {
        DEBUG, INFO, WARNING,ERROR,
    };
    static void log(const std::string& message, Level level = Level::INFO);
private:
    static Logger& getInstance();

    Logger() = default;
    ~Logger() = default;
    void print(const std::string& message,Level level);

};
Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
}
void Logger::print(const std::string& message, Level level) {
    switch (level) {
        case Level::DEBUG:
            std::count <<"[DEBUG]";
            break;
        case Level::WARNING:
            std::cout << "[INFO]";
            break;
        case Level::WARNING:
            std::cout << "[WARNING] ";
            break;
        case Level::ERROR:
            std::cout << "[ERROR] ";
            break;
    }
    std::cout << message << std::endl;
}
void Logger::log(const std::string& message, Level level) {
    getInstance().print(message, level);
}
