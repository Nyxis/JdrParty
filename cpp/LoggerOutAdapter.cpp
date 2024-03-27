//
// Created by admin on 25/03/2024.
//

#include "LoggerOutAdapter.h"
#include "StdOutLogger.h"
#include "FileOutLogger.h"
#include <string>
#include <iostream>

void LoggerOutAdapter::Display(std::string message, std::string method){
    if(method == "console"){
        StdOutLogger::Display(message);
    }
    else {
        if(method == "file"){
            FileOutLogger::StoreLog(message);
        }
        else
        {
            StdOutLogger::Display("Erreur : La méthode du logger n est ni cout ni file, method= "+method);
        }
    }
}