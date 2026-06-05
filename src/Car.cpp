#include "Car.h"

// Constructor: Chaining the Vehicle base class constructor
Car::Car(string b, string m, int y, int mil, string cond, double p, string id, 
        Engine e, Category c, string body, string trans, int doors, bool sunroof, float safety, double trunk)
    : Vehicle(b, m, y, mil, cond, p, id, e, c), bodyType(body), transmission(trans), doorCount(doors), hasSunroof(sunroof), safetyRating(safety), trunkCapacity(trunk) {}

Car::~Car() {
}

// Overriding Pure Virtual Function
void Car::displayDetails() const {
    cout<<"---[CAR LISTING]---"<<endl;
    cout<<"ID: "<<vehicleID <<" | Type: "<<bodyType<<endl;
    cout<<"Brand: "<<brand<<" "<<model<<" ("<<year<<")"<<endl;
    cout<<"Price: "<<price<<" PKR | Mileage: "<<mileage<<"km"<<endl;
    cout<<"Specs: "<<transmission<<" | Doors: "<<doorCount<<" | Sunroof: "<<(hasSunroof ? "Yes" : "No")<<endl;
    cout<<"Safety Rating: "<<safetyRating<<"/5.0 | Trunk: "<<trunkCapacity<<"L"<<endl;
    eng.displayEngine();
    cat.displayCategory();
    cout<<"-----------------------"<<endl;
}

// Function 1: Maintenance Logic
void Car::checkMaintenance() const {
    if (mileage > 50000 || (2026 - year) > 5) {
        cout<<"Maintenance Status: Full Service Required (High Mileage/Old)."<<endl;
    } else {
        cout<<"Maintenance Status: Regular Checkup sufficient."<<endl;
    }
}

// Function 2: Registration Logic
double Car::calculateRegistration() const {
    double baseReg = price * 0.02; // 2% base registration
    if (safetyRating > 4.0) {
        baseReg -= 5000; // Safety discount
    }
    return baseReg;
}

// Function 3: Safety Modifier
void Car::upgradeSafetyRating(float increase) {
    safetyRating += increase;
    if (safetyRating > 5.0) safetyRating = 5.0;
    cout<<"Safety systems upgraded. New Rating: "<<safetyRating<<endl;
}

// Function 4: Cargo Check
bool Car::canFitLuggage(double volume) const {
    return trunkCapacity >= volume;
}

// Definition: Operator Overloading (==)
bool Car::operator == (const Car& other) const {
    return (brand == other.brand && model == other.model);
}

// Definition: Operator Overloading (+)
double Car::operator + (const Car& other) const {
    return trunkCapacity + other.trunkCapacity;
}
