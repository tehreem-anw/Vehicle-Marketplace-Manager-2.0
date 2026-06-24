#pragma once
#include <iostream>
#include <string>
#include "Vehicle.h"
#include "SparePart.h"
#include "User.h"
using namespace std;

class Admin;

class Listing {
    const int listingID;          // CONSTANT MEMBER
    User* seller;                 // ASSOCIATION
    Vehicle* vPtr;                // AGGREGATION (Null if it's a part)
    SparePart* pPtr;              // AGGREGATION (Null if it's a vehicle)
    double price;
    string status;                // "Pending", "Approved", "Sold"
    static int totalListings;     // STATIC MEMBER

public:
    // Parameterized Constructor (Listing should have ID)
    Listing(int id, double p, User* s, Vehicle* v = nullptr, SparePart* sp = nullptr);
    ~Listing();

	//Friend Class
	friend class Admin;
	friend class Marketplace;

    // Member Functions
    void displayListing() const;
    void updatePrice(double newPrice);
	double calculateDiscountedPrice(double discountPercent);
    void markAsSold();

    // Getters
    int getID() const { return listingID; }
    string getStatus() const { return status; }
    double getPrice() const { return price; }
    Vehicle* getvPtr() const { return vPtr; }
    static int getTotalListings() { return totalListings; }

    // Declaration: Operator Overloading (==) to compare listing IDs
    bool operator == (int id) const;            
    //Declaration: Operator Overloading (>) to compare price
    bool operator > (const Listing& other) const; 
};
