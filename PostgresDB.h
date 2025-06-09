#pragma once
#include <pqxx/pqxx>
#include "Ticket.h"

class PostgresDB {
    pqxx::connection conn;

public:
    PostgresDB(const std::string& connStr);
    void insertTicket(const Ticket& ticket);
    void markTicketPaid(int ticketId);
};