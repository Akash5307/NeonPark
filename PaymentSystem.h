#pragma once
#include "Ticket.h"
#include <iostream>
#include <iomanip>

class PaymentSystem {
public:
    double calculateCharges(const Ticket& ticket) {
        auto now = std::chrono::system_clock::now();
        double hours = std::chrono::duration_cast<std::chrono::minutes>(now - ticket.GetEntryTime()).count() / 60.0;
        return std::max(20.0, hours * 10.0);
    }

    void makePayment(const Ticket& ticket) {
        double amount = calculateCharges(ticket);
        std::cout << "Payment of Rs. " << std::fixed << std::setprecision(2) << amount
                  << " for ticket ID: " << ticket.GetID() << " completed.\n";
    }
};
