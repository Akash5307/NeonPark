#pragma once
#include "Vehicle.h"
#include <chrono>
#include <memory>
#include <ctime>

class Ticket {
    int id;
    std::shared_ptr<Vehicle> vehicle;
    std::chrono::system_clock::time_point entry_time;
    int row, col;

public:
    Ticket()=default;
    Ticket(int id_, std::shared_ptr<Vehicle> v, int r, int c)
        : id(id_), vehicle(v), row(r), col(c), entry_time(std::chrono::system_clock::now()) {}

    int GetID() const { return id; }
    std::shared_ptr<Vehicle> GetVehicle() const { return vehicle; }
    std::string GetEntryTimeStr() const {
        std::time_t time = std::chrono::system_clock::to_time_t(entry_time);
        char buf[30];
        std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&time));
        return std::string(buf);
    }
    std::chrono::system_clock::time_point GetEntryTime() const { return entry_time; }
};
