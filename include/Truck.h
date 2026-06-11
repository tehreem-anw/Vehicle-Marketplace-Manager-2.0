#pragma once
#include "Vehicle.h"

class Truck : public Vehicle {
    double loadCapacity;      // In tons
    int axleCount;            // 2, 4, 6 etc.
    double towingCapacity;    // In kg
    string cargoType;         // Container, Flatbed, Tanker
    bool isHeavyDuty;
    double baseRatePerKm;     // PKR/km

public:
    // Parameterized Constructor (Vehicle base class)
    Truck(string b, string m, int y, int mil, string cond, double p, string id, 
          Engine e, Category c, double load, int axles, double towing, string cargo, bool heavy, double rate);
    
    // Destructor
    ~Truck();

    // Overriding Pure Virtual Function
    void displayDetails() const override;

    // Member Functions
    void checkLoadSafety() const;
    double calculateDeliveryFee(int distance) const;
    double calculateRouteTax() const;
    bool requiresSpecialPermit() const;

    // Declaration: Operator Overloading (==) for load capacity comparison
    bool operator == (const Truck& other) const;
    // Declaration: Operator Overloading (+) to combine Towing Capacity
    double operator + (const Truck& other) const;
};
