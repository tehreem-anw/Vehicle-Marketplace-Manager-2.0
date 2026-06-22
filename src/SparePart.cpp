#include "SparePart.h"

// Parameterized Constructor: Uses initializer list for the constant ID
SparePart::SparePart(string name, string manu, string cond, int id, string model, double w)
    : partName(name), manufacturer(manu), condition(cond), partID(id), compatibleModel(model), weight(w) {}

SparePart::~SparePart() {
}

// Function 1: Display Spare part Details
void SparePart::displaySparePart() const {
    cout<<"Part: "<<partName<<" ("<<partID<<")"<<" | Brand: "<<manufacturer<<endl;
    cout<<"Condition: "<<condition<<" | Weight: "<<weight<<"kg"<<endl;
    cout<<"Compatible with: "<<compatibleModel<<endl;
}

// Function 2: Compatibility Check (If it matches OR is a universal part)
bool SparePart::isCompatible(string carModel) const {
    if(carModel == compatibleModel || compatibleModel == "Universal") {
        return true;
    }
    return false;
}

// Function 3: Shipping Cost Logic (Base rate 10 PKR per kg per km)
double SparePart::calculateShipping(double distance) const {
    return weight * distance * 10.0;
}

// Function 4: Quality Status (New/Used)
void SparePart::printQualityStatus() const {
    if(condition == "New") {
        cout<<"Status: Brand New - 1 Year Warranty"<<endl;
    } else {
        cout<<"Status: Used - No Warranty"<<endl;
    }
}
