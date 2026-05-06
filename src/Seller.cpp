#include "Seller.h"

// Parameterized Constructor: Passes base data to User constructor
Seller::Seller(string n, string id, string e, Account a, string s): User(n, id, e, a), storeName (s) {
    adCount = 0;
    totalEarnings = 0.0;
    sellerRating = 0.0;
    reviewCount = 0;
    for(int i = 0; i < 10; i++){  // Initialize listings array with nullptrs
        activeAds[i] = nullptr;
    }
}

Seller::~Seller() {
}

// Function 1: Overriding Abstract Function
void Seller::viewProfile() const {
    cout<<"--- SELLER PROFILE ---"<<endl;
    cout<<"Store: "<<storeName<<" | Seller: "<<name<<endl;
    cout<<"ID: "<<userID<<" | Rating: "<<sellerRating<<"/5.0"<<endl;
    cout<<"Total Earnings: "<<totalEarnings<<" PKR"<<endl;
    acc.displayAccountInfo();
    cout<<"Active Listings: "<<adCount<<endl;
}

// Function 2: Add Listing (Aggregation Logic)
void Seller::addListing(Listing* lPtr) {
    if(adCount < 10){
        activeAds[adCount++] = lPtr;
        cout<<"Ad linked to seller account successfully!"<<endl;
    }else{
        cout<<"Maximum listing limit reached for this account."<<endl;
    }
}

// Function 3: Earnings Management
void Seller::updateEarnings(double amount) {
    if(amount > 0){
        totalEarnings = totalEarnings + amount;
        cout<<"Earnings updated: "<<totalEarnings<<" PKR"<<endl;
    }
}

// Function 4: Display All Seller Ads
void Seller::displayMyAds() const {
    if(adCount == 0){
        cout<<"You have no active listings."<<endl;
        return;
    }
    cout<<"--- YOUR ACTIVE LISTINGS ---"<<endl;
    for(int i = 0; i < adCount; i++){
        if(activeAds[i] != nullptr){
            // Calling Listing display logic
            activeAds[i]->displayListing();
        }
    }
}

// Function 5: Rating Management (Running Average Logic)
void Seller::updateRating() {
    if (sellerRating >= 0.0 && sellerRating <= 5.0) {
    	sellerRating += reviewCount * 0.05;
	}
}

// Implementation: Operator Overloading (+) 
Seller Seller::operator + (double amount) {
    totalEarnings = totalEarnings + amount;
    return *this;
}

// Implementation: Operator Overloading (==)
bool Seller::operator == (const string& sName) const {
    return storeName == sName;
}
