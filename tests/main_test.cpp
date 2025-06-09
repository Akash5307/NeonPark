//src/main_test.cpp
#include <gtest/gtest.h>
#include "../Vehicle.h"
#include "../Ticket.h"

TEST(VehicleTest, LicensePlate) {
    Vehicle v("TEST123", VehicleType::CAR);
    ASSERT_EQ(v.GetLicensePlate(), "TEST123");
    ASSERT_EQ(v.GetType(), "CAR");
}

TEST(TicketTest, EntryTimeFormat) {
    auto v = std::make_shared<Vehicle>("TEST456", VehicleType::BIKE);
    Ticket t(1, v, 0, 0);
    ASSERT_FALSE(t.GetEntryTimeStr().empty());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
