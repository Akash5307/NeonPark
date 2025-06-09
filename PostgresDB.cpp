#include "PostgresDB.h"

PostgresDB::PostgresDB(const std::string& connStr) : conn(connStr) {}

void PostgresDB::insertTicket(const Ticket& ticket) {
    pqxx::work txn(conn);
    txn.exec0(
        "INSERT INTO tickets (vehicle_type, license_plate, entry_time, is_paid) VALUES (" +
        txn.quote(ticket.GetVehicle()->GetType()) + ", " +
        txn.quote(ticket.GetVehicle()->GetLicensePlate()) + ", " +
        txn.quote(ticket.GetEntryTimeStr()) + ", false)");
    txn.commit();
}

void PostgresDB::markTicketPaid(int ticketId) {
    pqxx::work txn(conn);
    txn.exec0("UPDATE tickets SET is_paid = true, exit_time = NOW() WHERE id = " + txn.quote(ticketId));
    txn.commit();
}
