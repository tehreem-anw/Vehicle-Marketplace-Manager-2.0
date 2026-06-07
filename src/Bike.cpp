#include "Bike.h"

// Constructor: Chaining the Vehicle base class constructor
Bike::Bike(string b, string m, int y, int mil, string cond, double p, string id, 
         Engine e, Category c, int d, float avg, int g, int w, string wheel, string start)
    : Vehicle(b, m, y, mil, cond, p, id, e, c), displacement(d), fuelAverage(avg), groundClearance(g), dryWeight(w), wheelSize(wheel), startingSystem(start) {}

Bike::~Bike() {
}

// Overriding Pure Virtual Function
void Bike::displayDetails() const {
    cout<<"---[BIKE LISTING]---"<<endl;
    cout<<"ID: "<<vehicleID<<" | Displacement: "<<displacement<<"cc"<<endl;
    cout<<"Brand: "<<brand<<" "<<model<<" ("<<year<<")"<<endl;
    cout<<"Price: "<<price<<" PKR | Fuel Avg: "<<fuelAverage<<" KM/L"<<endl;
    cout<<"Ground Clearance: "<<groundClearance<<"mm | Dry Weight: "<<dryWeight<<"KG"<<endl;
    cout<<"Wheel Size: "<<wheelSize<<" | Starting: "<<startingSystem<<endl;
    eng.displayEngine();
    cat.displayCategory();
    cout<<"-----------------------"<<endl;
}

// Function 1: Efficiency Logic
void Bike::analyzeFuelEconomy() const {
    if (fuelAverage >= 40.0) {
        cout<<"Economy Status: Highly Fuel Efficient (Commuter Class)."<<endl;
    } else {
        cout<<"Economy Status: Performance Focused / Heavy Fuel Consumption."<<endl;
    }
}

// Function 2: Terrain Suitability
void Bike::checkTerrainCapability() const {
    if (groundClearance >= 140) {
        cout<<"Terrain Status: Suitable for rough roads."<<endl;
    } else {
        cout<<"Terrain Status: Low - Caution on uneven surfaces."<<endl;
    }
}

// Function 3: Power-to-Weight Ratio
double Bike::calculatePowerWeightRatio(int hp) const {
    if (dryWeight == 0) return 0;
    return (double)hp / dryWeight;
}

// Function 4: Starting Mechanism Status
void Bike::checkBatteryHealth() const {
    if (startingSystem.find("Electric") != string::npos) {
        cout<<"Service Note: Inspect battery for Electric Start reliability."<<endl;
    } else {
        cout<<"Service Note: Mechanical kickstart only."<<endl;
    }
}

// Definition: Operator Overloading (==)
bool Bike::operator == (const Bike& other) const {
    return (displacement == other.displacement && brand == other.brand);
}

// Definition: Operator Overloading (+)
int Bike::operator + (const Bike& other) const {
    return dryWeight + other.dryWeight;
}
