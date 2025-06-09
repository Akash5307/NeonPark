#include "ParkingLot.h"
#include <iostream>

ParkingLot::ParkingLot(int r, int c, PostgresDB& db_) : rows(r), cols(c), db(db_) {
    grid = std::vector<std::vector<bool>>(r, std::vector<bool>(c, false));
}

std::optional<Ticket> ParkingLot::parkVehicle(std::shared_ptr<Vehicle> vehicle) {
    std::lock_guard<std::mutex> lock(mtx);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (!grid[i][j]) {
                grid[i][j] = true;
                int id = ticketCounter++;
                Ticket ticket(id, vehicle, i, j);
                // activeTickets[id] = ticket;
                activeTickets.insert({id, ticket});
                db.insertTicket(ticket);
                Logger::log("Parked vehicle: " + vehicle->GetLicensePlate());
                return ticket;
            }
        }
    }
    return std::nullopt;
}

void ParkingLot::unparkVehicle(int ticketId) {
    std::lock_guard<std::mutex> lock(mtx);
    if (activeTickets.find(ticketId) == activeTickets.end()) return;
    Ticket ticket = activeTickets[ticketId];
    grid[ticket.GetID() % rows][ticket.GetID() % cols] = false;
    paymentSystem.makePayment(ticket);
    db.markTicketPaid(ticketId);
    activeTickets.erase(ticketId);
    Logger::log("Unparked ticket ID: " + std::to_string(ticketId));
}

void ParkingLot::printStatus() {
    for (auto& row : grid) {
        for (auto spot : row) std::cout << (spot ? "[X] " : "[ ] ");
        std::cout << "\n";
    }
}