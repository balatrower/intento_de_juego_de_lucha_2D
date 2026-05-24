//
// Created by p0wer on 24/05/2026.
//

#include "core/Logger.h"
#include <fstream>
#include <chrono>
#include <iomanip>
#include <iostream>

namespace Logger {
    void error(const std::string& message) {
        std::ofstream logFile("MainLog.log", std::ios::app);
        if (logFile.is_open()) {
            auto timeNow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            logFile << "[" << std::put_time(std::localtime(&timeNow), "%Y-%m-%d %H:%M:%S") << "] "
                    << "[ERROR] " << message << std::endl;
        }
        std::cerr << "[ERROR] " << message << std::endl;
    }

    void info(const std::string& message) {
        std::ofstream logFile("MainLog.log", std::ios::app);
        if (logFile.is_open()) {
            auto timeNow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            logFile << "[" << std::put_time(std::localtime(&timeNow), "%Y-%m-%d %H:%M:%S") << "] "
                    << "[INFO]  " << message << std::endl;
        }
        std::cout << "[INFO]  " << message << std::endl;
    }

}