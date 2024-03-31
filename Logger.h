#include <string>
#include <iostream>

class Logger
{
private:
    static Logger *instance;

public:
    static Logger *getInstance();
    void log(const std::string &message);
};