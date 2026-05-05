#pragma once
#include "User.h"
#include "Vehicle.h"

class Buyer : public User {
    Vehicle* favorites[10];       // AGGREGATION 1 - Array of pointers to vehicles
    int favCount;                 // To track how many favorites exist
    double budget;
    string preferredType;         // SUV, Sedan, etc.
    string city;

public:
    // Parameterized Constructor (User base class)
    Buyer(string n, string id, string e, Account a, double b, string pref, string c);
    ~Buyer();

    // Member Functions
    void viewProfile() const override;
    void saveFavorite(Vehicle* vPtr);
    void updateBudget(double newBudget);
    void displayFavorites() const;

    // Declaration: Operator Overloading (+) to increase budget
    Buyer operator + (double extraBudget);
    // Declaration: Operator Overloading (>) to compare budget
    bool operator > (const Buyer& other) const;
};
