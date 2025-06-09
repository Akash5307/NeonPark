#include "ParkingLot.h"
#include <thread>

void simulate(ParkingLot& lot, std::shared_ptr<Vehicle> vehicle, int delay) {
    auto ticket = lot.parkVehicle(vehicle);
    if (!ticket) return;
    std::this_thread::sleep_for(std::chrono::seconds(delay));
    lot.unparkVehicle(ticket->GetID());
}

int main() {
    PostgresDB db("postgresql://neondb_owner:npg_suhjTH7v3WgX@ep-noisy-sound-a54nepy7-pooler.us-east-2.aws.neon.tech/neondb?sslmode=require");
    ParkingLot lot(5, 5, db);

    std::thread t1(simulate, std::ref(lot), std::make_shared<Vehicle>("KA01AB1234", VehicleType::CAR), 5);
    std::thread t2(simulate, std::ref(lot), std::make_shared<Vehicle>("UP14XY5678", VehicleType::BIKE), 4);

    t1.join();
    t2.join();

    lot.printStatus();
    return 0;
}
