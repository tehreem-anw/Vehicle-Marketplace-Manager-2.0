#include "Vehicle.h"

// Initialization: Static member
int Vehicle::vehicleCount = 0;

// Constructor: Uses Initializer List for Const, Composition, and Base members
Vehicle::Vehicle(string b, string m, int y, int mil, string cond, double p, string id, Engine e, Category c) 
: brand(b), model(m), year(y), mileage(mil), condition(cond), price(p), vehicleID(id), eng(e), cat(c), isAvailable(true) {
    vehicleCount++;
}

Vehicle::~Vehicle() {
    vehicleCount--;
}

// Function 1: Mileage Validation
void Vehicle::updateMileage(int newMileage) {
    if(newMileage >= mileage){
        mileage = newMileage;
        cout<<"Mileage updated successfully."<<endl;
    }else{
        cout<<"Error: Mileage tampering detected."<<endl;
    }
}

// Function 2: Value Depreciation
double Vehicle::calculateCurrentValue() const {
    int age = 2026 - year;
    double factor = 1.0;
    for(int i = 0; i < age; i++){
        factor *= 0.90; // 10% loss per year
    }
    return price * factor;
}

// Function 3: Status Checker
void Vehicle::checkVehicleStatus() const {
    if(mileage > 100000 || (2026 - year) > 10){
        cout<<"Status: High Mileage/Old Vehicle"<<endl;
    }else{
        cout<<"Status: Excellent Condition"<<endl;
    }
}

// Function 4: Price Management
void Vehicle::updatePrice(double newPrice) {
    if(newPrice > 0){
        price = newPrice;
        cout<<"Price updated to: "<<price<<" PKR"<<endl;
    }
}

void Vehicle::markAsSold() {
    isAvailable = false;
    cout<<"Vehicle "<<vehicleID<<" marked as sold."<<endl;
}

bool Vehicle::checkAvailability() const {
    return isAvailable;
}

int Vehicle::getvehicleCount() {
    return vehicleCount;
}

// Implementation: Operator Overloading (==)
bool Vehicle::operator == (const string& id) const {
    return vehicleID == id;
}

// Implementation: Operator Overloading (>)
bool Vehicle::operator > (const Vehicle& v) const {
    return price > v.price;
}
