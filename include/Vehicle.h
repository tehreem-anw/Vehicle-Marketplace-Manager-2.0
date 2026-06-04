#pragma once
#include <iostream>
#include <string>
#include "Engine.h"  
#include "Category.h" 
using namespace std;

class Vehicle {
protected:
    string brand;
    string model;
    string condition;
    int year;
    int mileage;
    double price;
    const string vehicleID;      // CONSTANT MEMBER
    bool isAvailable;
    Engine eng;                  // COMPOSITION 1
    Category cat;                // COMPOSITION 2
    static int vehicleCount;     // STATIC MEMBER

public:
    // Parameterized Constructor (Vehicle should have a brand, mileage, year, etc.)
    Vehicle(string b, string m, int y, int mil, string cond, double p, string id, Engine e, Category c);
    
	// Virtual destructor for inheritance safety
	virtual ~Vehicle();

    // Pure Virtual Function (Abstraction)
    virtual void displayDetails() const = 0;

    // Member Functions
    void updateMileage(int newMileage);
    double calculateCurrentValue() const;
    void checkVehicleStatus() const;
    void updatePrice(double newPrice);
    void markAsSold();
    bool checkAvailability() const;
    static int getvehicleCount(); // Static Function

    // Declaration: Operator Overloading (==) for ID comparison
    bool operator == (const string& id) const;
    
    // Declaration: Operator Overloading (>) for Price comparison
    bool operator > (const Vehicle& v) const;

    // Getters
    string getBrand() const { return brand; }
    string getModel() const { return model; }
    double getPrice() const { return price; }
    int getYear() const { return year; }
    int getMileage() const { return mileage; }
};
