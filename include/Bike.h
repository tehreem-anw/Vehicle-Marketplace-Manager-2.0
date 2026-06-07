#pragma once
#include "Vehicle.h"

class Bike : public Vehicle {
    int displacement;         // cc
    float fuelAverage;        // km/l
    int groundClearance;      // mm
    int dryWeight;            // kg
    string wheelSize;         // inches
    string startingSystem;    // Kick/Electric Start

public:
    // Parameterized Constructor (Vehicle base class)
    Bike(string b, string m, int y, int mil, string cond, double p, string id, 
         Engine e, Category c, int disp, float avg, int ground, int weight, string wheel, string start);
    //Destructor
    ~Bike();

    // Overriding Pure Virtual Function
    void displayDetails() const override;

	//Member Functions
    void analyzeFuelEconomy() const;
    void checkTerrainCapability() const;
    double calculatePowerWeightRatio(int hp) const;
    void checkBatteryHealth() const;

    // Declaration: Operator Overloading (==) for displacement comparison
    bool operator == (const Bike& other) const;
    // Declaration: Operator Overloading (+) to combine Dry Weight
    int operator + (const Bike& other) const;
};
