#ifndef JDR_LOGGER_H
#define JDR_LOGGER_H
#include <iostream>

 class Logger {
 public:
     enum gameLogs {start = 1, end = 0, coin = 2, dices = 3, cards = 4};
     static void log(int msg);
     static void gameTypeLog(std::string str);
     static void showResult();
};
#endif //JDR_LOGGER_H
