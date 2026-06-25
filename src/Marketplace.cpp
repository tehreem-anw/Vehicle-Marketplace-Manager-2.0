#include "Marketplace.h"

// Initialization:  Static member
int Marketplace::totalVisits = 0;

// Parameterized Constructor
Marketplace::Marketplace(string region) : regionCode(region), adCount(0), userCount(0) {}

Marketplace::~Marketplace() {
}

// Function 1: Register User (Limit 50 per Reigon)
void Marketplace::registerUser(User* u) {
    if(userCount < 50) {
        allUsers[userCount++] = u;
        totalVisits++; 
    } else {
        cout<<"Error: Region user limit reached."<<endl;
    }
}

// Function 2: Post an Ad (Limit 100 per Region)
void Marketplace::postAd(Listing* l) {
    if(adCount < 100) {
        allAds[adCount++] = l;
        totalVisits++;
        cout<<"Ad posted successfully in region: "<<regionCode<<endl;
    } else {
        cout<<"Error: Region Ad limit reached."<<endl;
    }
}

// Function 3: Search Logic (Filtering)
void Marketplace::filterMarket() const {
    int choice;
    cout<<"--- Search & Filter Menu ---"<<endl;
    cout<<"1. Search by Brand"<<endl;
    cout<<"2. Search by Year"<<endl;
    cout<<"3. Search by Max Price"<<endl;
    cout<<"4. Search by Max Mileage"<<endl;
    cout<<"Enter choice: ";
    cin>>choice;

    switch(choice) {
        case 1: {
            string b;
            cout<<"Enter Brand: "; cin>>b;
            for(int i=0; i<adCount; i++) {
                if(allAds[i]->getvPtr() != nullptr && allAds[i]->getvPtr()->getBrand() == b) {
                    allAds[i]->displayListing();
                    cout<<endl;
                }
            }
            break;
        }
        case 2: {
            int y;
            cout<<"Enter Year: "; cin>>y;
            for(int i=0; i<adCount; i++) {
                if(allAds[i]->getvPtr() != nullptr && allAds[i]->getvPtr()->getYear() == y) {
                    allAds[i]->displayListing();
                    cout<<endl;
                }
            }
            break;
        }
        case 3: {
            double p;
            cout<<"Enter Max Price: "; cin>>p;
            for(int i=0; i<adCount; i++) {
                if(allAds[i]->price <= p) {
                    allAds[i]->displayListing();
                    cout<<endl;
                }
            }
            break;
        }
        case 4: {
            int m;
            cout<<"Enter Max Mileage: "; cin>>m;
            for(int i=0; i<adCount; i++) {
                if(allAds[i]->getvPtr() != nullptr && allAds[i]->getvPtr()->getMileage() <= m) {
                    allAds[i]->displayListing();
                    cout<<endl;
                }
            }
            break;
        }
        default:
            cout<<"Invalid choice."<<endl;
    }
}

// Function 4: Marketplace Stats
void Marketplace::displayMarketStats() const {
    cout<<"Marketplace Region: "<<regionCode<<endl;
    cout<<"Active Users: "<<userCount<<" | Total Ads: "<<adCount<<endl;
    cout<<"Total Platform Visits: "<<totalVisits<<endl;
}
