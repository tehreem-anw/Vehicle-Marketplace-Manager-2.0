#pragma once
#include "User.h"
#include "Listing.h" 

class Seller : public User {
    Listing* activeAds[10];       // AGGREGATION - Array of pointers to listings
    int adCount;
    double totalEarnings;
    float sellerRating;
    string storeName;
    int reviewCount;

public:
    // Parameterized Constructor (User base class)
    Seller(string n, string id, string e, Account a, string sName);
    
	//Destructor
	~Seller();

    // Member Functions
    void viewProfile() const override;
    void addListing(Listing* lPtr);
    void updateEarnings(double amount);
    void displayMyAds() const;
    void updateRating();

    // Declaration: Operator Overloading (+) to add to earnings
    Seller operator + (double amount);
    
    // Declaration: Operator Overloading (==) to compare store names
    bool operator == (const string& sName) const;
};
