#include "Listing.h"

// Initialize static member
int Listing::totalListings = 0;

// Constructor: Uses Initializer List for const ID and pointers
Listing::Listing(int id, double p, User* s, Vehicle* v, SparePart* sp)
    : listingID(id), price(p), seller(s), vPtr(v), pPtr(sp), status("Pending") {
    totalListings++;
}

Listing::~Listing() {
    totalListings--;
}

// Function 1: Display Logic
void Listing::displayListing() const {
    cout<<"---[LISTING AD: "<<listingID<<"]---"<<endl;
    cout<<"Status: " << status << " | Price: " << price << " PKR" << endl;
    if (vPtr != nullptr) { 		  //If Vehicle AD
        vPtr->displayDetails();
    } 
    else if (pPtr != nullptr) {	  //If Spare part AD
        pPtr->displaySparePart();
    } 
    else {
        cout<<"Error: This listing has no ads."<<endl;
    }
    cout<<"-----------------------------------"<<endl;
}

// Function 2: Price Update Logic
void Listing::updatePrice(double newPrice) {
    if (newPrice > 0) {
        price = newPrice;
        cout<<"Listing ["<<listingID<<"] - Price updated to: "<<price<<" PKR"<<endl;
    } else {
        cout<<"Error: Invalid Price!"<<endl;
    }
}

// Function 3: Discount Logic
double Listing::calculateDiscountedPrice(double discountPercent) {
    if (discountPercent > 0 && discountPercent <= 100) {
        double discountAmount = (price * discountPercent) / 100;
        return price - discountAmount;
    }
    return price; // No discount applied if discount percentage is invalid
}

// Function 4: Sale Logic
void Listing::markAsSold() {
    status = "Sold";
    // If it's a vehicle, also update vehicle's "markAsSold" status
    if (vPtr != nullptr) {
        vPtr->markAsSold();
    }
    cout<<"Listing ["<<listingID<<"]: Marked as sold."<<endl;
}

// Implementation: Operator Overloading (==)
bool Listing::operator == (int id) const {
    return listingID == id;
}

// Implementation: Operator Overloading (>)
bool Listing::operator > (const Listing& other) const {
    return price > other.price;
}
