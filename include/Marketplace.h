#pragma once
#include <iostream>
#include <string>
#include "Listing.h"
#include "User.h"
using namespace std;

class Marketplace {
    Listing* allAds[100];         // Aggregation of Ads
    User* allUsers[50];           // Aggregation of Users
    int adCount;
    int userCount;
    string regionCode;
    static int totalVisits;       // Static Member

public:
    // Parameterized Constructor (Marketplace should have reigon. Initializes count)
    Marketplace(string region);
    
    //Destructor
    ~Marketplace();

    // Member Functions
    void registerUser(User* u);
    void postAd(Listing* l);
    void filterMarket() const;
    void displayMarketStats() const;

    // Getters
    static int getTotalVisits() {return totalVisits;} 	//Static Function
    int getAdCount() const {return adCount;}
    int getUserCount() const {return userCount;}
    string getRegion() const {return regionCode;}
};
