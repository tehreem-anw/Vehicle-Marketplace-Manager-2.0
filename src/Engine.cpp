#include "Engine.h"

// Default Constructor
Engine::Engine(): capacityCC(0), fuelType("Petrol"), horsepower(0), transmissionType("Manual"), engineSerial("0000"), cylinderCount(4) {}

// Parameterized Constructor: Uses Initializer List for the constant Serial
Engine::Engine(float cc, string fuel, int hp, string trans, string serial, int cylinders)
    : capacityCC(cc), fuelType(fuel), horsepower(hp), transmissionType(trans), engineSerial(serial), cylinderCount(cylinders) {}

Engine::~Engine() {
}

// Function 1: Display Engine Details
void Engine::displayEngine() const {
    cout<<"Engine: "<<capacityCC<<"cc | Fuel: "<<fuelType<<endl;
    cout<<"Transmission: "<<transmissionType<<" | HP: "<<horsepower<<endl;
    cout<<"Serial: "<<engineSerial<<" | Cylinders: "<<cylinderCount<<endl;
}

// Function 2: Fuel Efficiency Logic
void Engine::checkFuelEfficiency() const {
    if(fuelType == "CNG") {
        cout<<"Efficiency: Maximum (Eco-Friendly)"<<endl;
    } else if(fuelType == "Diesel") {
        cout<<"Efficiency: High (Long Distance)"<<endl;
    } else {
        cout<<"Efficiency: Standard"<<endl;
    }
}

// Function 3: Validation for Horsepower
bool Engine::isSportsGrade() const {
    return (horsepower > 250 && cylinderCount >= 6);
}

// Function 4: Horsepower Modifier
void Engine::upgradeHorsepower(int boost) {
    horsepower += boost;
    cout<<"Horsepower upgraded to: "<<horsepower<<endl;
}
