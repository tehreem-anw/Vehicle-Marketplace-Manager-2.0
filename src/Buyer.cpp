#include "Buyer.h"

// Parameterized Constructor: Uses initializer list for the User base class
Buyer::Buyer(string n, string id, string e, Account a, double b, string p, string c): User(n, id, e, a), budget(b), preferredType(p), city(c) {
    favCount = 0;
    for(int i = 0; i < 10; i++){  // Initialize favorites array with nullptrs
        favorites[i] = nullptr;
    }
}

Buyer::~Buyer() {
}

// Function 1: Overriding Abstract Function 
void Buyer::viewProfile() const {
    cout<<"--- BUYER PROFILE ---"<<endl;
    cout<<"Name: "<<name<<" | ID: "<<userID<<endl;
    cout<<"City: "<<city<<" | Budget: "<<budget<<" PKR"<<endl;
    cout<<"Preference: "<<preferredType<<endl;
    acc.displayAccountInfo();
    cout<<"Favorites saved: "<<favCount<<endl;
}

// Function 2: Add to Favorites (Aggregation Logic)
void Buyer::saveFavorite(Vehicle* vPtr) {
    if(favCount < 10){
        favorites[favCount++] = vPtr;
        cout<<vPtr->getModel()<<" added to favorites!"<<endl;
    }else{
        cout<<"Favorites list is full."<<endl;
    }
}

// Function 3: Budget Management
void Buyer::updateBudget(double newBudget) {
    budget = newBudget;
    cout<<"Budget updated to: "<<budget<<endl;
}

// Function 4: Display All Favorites
void Buyer::displayFavorites() const {
    if(favCount == 0){
        cout<<"No favorites saved yet."<<endl;
        return;
    }
    cout<<"--- YOUR FAVORITE VEHICLES ---"<<endl;
    for(int i = 0; i < favCount; i++){
        if(favorites[i] != nullptr){
            cout<<(i+1)<<". "<<favorites[i]->getBrand()<<" "<<favorites[i]->getModel()<<endl;
        }
    }
}

// Implementation: Operator Overloading (+)
Buyer Buyer::operator + (double extraBudget) {
    budget = budget + extraBudget;
    return *this;
}

// Implementation: Operator Overloading (>)
bool Buyer::operator > (const Buyer& other) const {
    return budget > other.budget;
}
