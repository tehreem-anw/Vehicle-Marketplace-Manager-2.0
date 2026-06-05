#pragma once
#include "Vehicle.h"

class Car : public Vehicle {
    string bodyType;          // Sedan, Hatchback, SUV
    string transmission;      // Automatic, Manual
    int doorCount;
    bool hasSunroof;
    float safetyRating;       // Out of 5.0
    double trunkCapacity;     // In Liters

public:
    // Parameterized Constructor (Vehicle base class)
    Car(string b, string m, int y, int mil, string cond, double p, string id, 
        Engine e, Category c, string body, string trans, int doors, bool sunroof, float safety, double trunk);
    
	//Destructor
    ~Car();

    // Overriding the Pure Virtual Function
    void displayDetails() const override;

	// Member Functions
    void checkMaintenance() const;
    double calculateRegistration() const;
    void upgradeSafetyRating(float increase);
    bool canFitLuggage(double volume) const;

    // Declaration: Operator Overloading (==) to compare car models
    bool operator == (const Car& other) const;
    // Declaration: Operator Overloading (+) to combine trunk capacity
    double operator + (const Car& other) const;
};
