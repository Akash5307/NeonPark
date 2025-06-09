#pragma once
#include <vector>
#include <map>
#include <mutex>
#include <optional>
#include "Ticket.h"
#include "PaymentSystem.h"
#include "Logger.h"
#include "PostgresDB.h"

class ParkingLot {
    int rows, cols;
    std::vector<std::vector<bool>> grid;
    std::map<int, Ticket> activeTickets;
    int ticketCounter = 1;
    std::mutex mtx;
    PaymentSystem paymentSystem;
    PostgresDB& db;

public:
    
    ParkingLot(int r, int c, PostgresDB& db_);
    std::optional<Ticket> parkVehicle(std::shared_ptr<Vehicle> vehicle);
    void unparkVehicle(int ticketId);
    void printStatus();
};
