#pragma once
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>

class Logger {
public:
    static void log(const std::string& message) {
        std::ofstream file("log.txt", std::ios::app);
        auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        file << std::ctime(&now) << ": " << message << std::endl;
    }
};