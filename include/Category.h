#pragma once
#include <iostream>
#include <string>
using namespace std;

class Category {
    string typeName;              // "Car", "Bike", "Truck"
    string licenseRequired;       // "LTV", "HTV", etc.
    const double baseTaxRate;     // CONSTANT MEMBER
    bool isCommercial;

public:
    // Constructors
    Category();
    // Parameterized Constructor (Category should have name, license, tax and commercial status)
    Category(string name, string license, double tax, bool comm);
    
    //Destructor
    ~Category();

    // Member Functions
    void displayCategory() const;
    double calculateTax(double price) const;
    bool checkLicenseMatch(string userLicense) const;
    
    // Getter
    double getBaseTax() const { return baseTaxRate; }
};
