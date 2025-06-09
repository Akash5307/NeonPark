#pragma once
#include <string>

enum class VehicleType { CAR, BIKE, TRUCK };

class Vehicle {
    std::string plateNumber;
    VehicleType type;

public:
    Vehicle(std::string plate, VehicleType t) : plateNumber(plate), type(t) {}
    std::string GetLicensePlate() const { return plateNumber; }
    std::string GetType() const {
        switch (type) {
            case VehicleType::CAR: return "CAR";
            case VehicleType::BIKE: return "BIKE";
            case VehicleType::TRUCK: return "TRUCK";
        }
        return "UNKNOWN";
    }
};