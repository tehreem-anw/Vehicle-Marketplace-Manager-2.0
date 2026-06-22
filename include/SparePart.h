#pragma once
#include <iostream>
#include <string>
using namespace std;

class SparePart {
    string partName;
    string manufacturer;
    string condition;             // New/Used
    const int partID;             // CONSTANT MEMBER
    string compatibleModel;
    double weight;

public:
    // Parameterized Constructor (Spare part should have nam, manufacturer, id, etc)
    SparePart(string name, string manu, string cond, int id, string model, double w);
    
    //Destructor
    ~SparePart();

    // Member Functions
    void displaySparePart() const;
    bool isCompatible(string carModel) const;
    double calculateShipping(double distance) const;
    void printQualityStatus() const;

    // Getters
    int getPartID() const { return partID; }
    string getPartName() const { return partName; }
};
