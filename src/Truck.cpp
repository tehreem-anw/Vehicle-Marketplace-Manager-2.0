#include "Truck.h"

// Constructor: Chaining the Vehicle base class constructor
Truck::Truck(string b, string m, int y, int mil, string cond, double p, string id, 
          Engine e, Category c, double load, int axles, double towing, string cargo, bool heavy, double rate)
    : Vehicle(b, m, y, mil, cond, p, id, e, c), loadCapacity(load), axleCount(axles), towingCapacity(towing), cargoType(cargo), isHeavyDuty(heavy), baseRatePerKm(rate) {}

Truck::~Truck() {
}

// Overriding Pure Virtual Function
void Truck::displayDetails() const {
    cout<<"---[TRUCK LISTING]---"<<endl;
    cout<<"ID: "<<vehicleID<<" | Cargo: "<<cargoType<<endl;
    cout<<"Brand: "<<brand<<" "<<model<<" ("<<year<<")"<<endl;
    cout<<"Price: "<<price<<" PKR | Load Capacity: "<<loadCapacity<<" Tons"<<endl;
    cout<<"Axles: "<<axleCount<<" | Towing: "<<towingCapacity<<"KG"<<endl;
    cout<<"Rate/KM: "<<baseRatePerKm<<" PKR | Heavy Duty: "<<(isHeavyDuty ? "Yes" : "No")<<endl;
    eng.displayEngine();
    cat.displayCategory();
    cout<<"-----------------------"<<endl;
}

// Function 1: Load Safety Logic according to Heavy Duty factor
void Truck::checkLoadSafety() const {
    if (loadCapacity > 15.0 && !isHeavyDuty) {
        cout<<"Safety Warning: Load exceeds chassis limit for non-heavy duty truck."<<endl;
    } else {
        cout<<"Safety Status: Load within structural parameters."<<endl;
    }
}

// Function 2: Delivery Fee Logic
double Truck::calculateDeliveryFee(int distance) const {
    double total = distance * baseRatePerKm;
    if (isHeavyDuty) {
        total *= 1.15; // 15% extra for heavy duty
    }
    return total;
}

// Function 3: Route Tax Logic (more axles, more tax)
double Truck::calculateRouteTax() const {
    return (double)axleCount * 500.0;
}

// Function 4: Permit Requirement Check 
bool Truck::requiresSpecialPermit() const {
    return (loadCapacity > 25.0 || axleCount > 6);
}

// Definition: Operator Overloading (==)
bool Truck::operator == (const Truck& other) const {
    return (loadCapacity == other.loadCapacity && axleCount == other.axleCount);
}

// Definition: Operator Overloading (+)
double Truck::operator + (const Truck& other) const {
    return towingCapacity + other.towingCapacity;
}
