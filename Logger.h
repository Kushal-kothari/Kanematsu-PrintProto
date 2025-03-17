#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>

class Logger {
public:
    static void log(const std::string& message) {
        std::cout << message << std::endl;
        std::ofstream logFile("log.txt", std::ios_base::app);
        if (logFile) {
            logFile << message << std::endl;
        }
    }
};

#endif
