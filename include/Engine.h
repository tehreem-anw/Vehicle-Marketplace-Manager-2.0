#pragma once
#include <iostream>
#include <string>
using namespace std;

class Engine {
    float capacityCC;
    string fuelType;             // Petrol/Diesel/CNG
    int horsepower;
    string transmissionType;     // Manual/Auto
    const string engineSerial;   // CONSTANT MEMBER
    int cylinderCount;

public:
    // Constructors
    Engine();
    // Parameterized Constructor (Engine should have capacity, fuel type, horsepower, etc.)
    Engine(float cc, string fuel, int hp, string trans, string serial, int cylinders);
    
    //Destructor
    ~Engine();
    
    // Member Functions
    void displayEngine() const;
    void checkFuelEfficiency() const;
    bool isSportsGrade() const;
    void upgradeHorsepower(int boost);

    // Getters (needed for some vehicle logic)
    float getCapacity() const { return capacityCC; }
    string getFuelType() const { return fuelType; }
};
