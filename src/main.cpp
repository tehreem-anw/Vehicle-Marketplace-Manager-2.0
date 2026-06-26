#include <iostream>
#include <string>

// Header Links
#include "Account.h"
#include "User.h"
#include "Seller.h"
#include "Buyer.h"
#include "Admin.h"
#include "Vehicle.h"
#include "Engine.h"
#include "Category.h"
#include "Car.h"
#include "Bike.h"
#include "Truck.h"
#include "SparePart.h"
#include "Message.h"
#include "Listing.h"
#include "Marketplace.h"

using namespace std;

int main() {
    // === 1. Engine & Category Objects ===
    Engine e1(1500, "Petrol", 180, "Auto", "ENG123", 4);
    Engine e2(8900, "Diesel", 200, "Manual", "ENG456", 6);
    Engine e3(150, "Petrol", 120, "Manual", "ENG789", 1);
    Category c1("Car", "LTV", 0.02, false);
    Category c2("Truck", "HTV", 0.05, true);
    Category c3("Bike", "LTV", 0.01, false);
    
    // === 2. Car, Bike & Truck Creation ===
    Car v1("Toyota", "Corolla", 2022, 15000, "New", 2700000, "V101", e1, c1, "Sedan", "Auto", 4, true, 4.5, 470.0);
    Car v2("Kia", "Sportage", 2021, 2000, "New", 6700000, "V102", e1, c1, "SUV", "Auto", 4, true, 4.5, 470.0);
    Truck v3("Suzuki", "Carry", 2015, 67000, "Old", 8900000, "V103", e2, c2, 15.0, 6, 20000.0, "Logistics", true, 150.0);
    Bike v4("Yamaha", "YBR", 2023, 500, "New", 450000, "V104", e3, c3, 125, 45.0, 145, 114, "18-inch", "Electric");

	// === 3. User account creation: Buyer & Seller ===
    Account acc1(101, "shafeek", "fhaa123", "06/07/2016");
    Seller u1("Shafqat", "S0889", "shafqat@jameel.com", acc1, "Shafeeq & Sons"); 
    
    Account acc2(102, "treemhehe", "hehe123", "07/01/2007");
    Buyer u2("Treem", "T0667", "troomtroom@jameel.com", acc2, 670000, "SUV", "Karachi"); 

	// === 4. Listing Creation ===
    Listing l1(6700, 2700000, &u1, &v1);
    Listing l2(6701, 670000, &u1, &v2);
    Listing l3(6702, 8900000, &u1, &v3);
    Listing l4(6703, 450000, &u1, &v4);
    
    // === 5. Marketplace Creation: Posting ADs ===
    Marketplace khiMarket("Karachi");
    khiMarket.registerUser(&u1);
    khiMarket.registerUser(&u2);
    khiMarket.postAd(&l1);
    khiMarket.postAd(&l2);
    khiMarket.postAd(&l3);
    
    // === Testing rest of functions ===
    
    // Vehicle, Engine, Category
    cout<<"===Vehicle, Engine, Category Testing==="<<endl;
    cout<<"Is v3 Sports Grade?"<<endl;
    if(e2.isSportsGrade()){
        cout<<"Yes."<<endl;
    }
    else{
        cout<<"No."<<endl;
    }
    e2.upgradeHorsepower(250);
    cout<<"Is v3 Sports Grade after upgrade?"<<endl;
    if(e2.isSportsGrade()){
        cout<<"Yes."<<endl;
    }
    else{
        cout<<"No."<<endl;
    }
    cout<<"Current Value of v2 (2026): "<<(long)v2.calculateCurrentValue()<<endl;
    cout<<"Vehicle Status: ";
    v2.checkVehicleStatus();
    v1.updateMileage(2000);         // should detect tampering
    v1.updateMileage(20000);        // should allow modification
    cout<<"Tax for v3: "<<c2.calculateTax(8900000)<<endl;

    // Spare Parts
    cout<<endl<<"===Spare Parts Testing==="<<endl;
    SparePart sp1("Alloy Rim", "Kamran Autos", "New", 6767, "Sportage", 45);
    sp1.displaySparePart();
    cout<<"Is compatible for Sportage?"<<endl;
    if(sp1.isCompatible("Sportage")) cout<<"Yes"<<endl; else cout<<"No"<<endl;
    cout<<endl<<"Is compatible for Corolla?"<<endl;
    if(sp1.isCompatible("Corolla")) cout<<"Yes"<<endl; else cout<<"No"<<endl;
    cout<<endl<<"Quality Status: ";
    sp1.printQualityStatus();
    cout<<"Shipping price for 20 km: "<<sp1.calculateShipping(20)<<endl;
    
    // User & Security
    cout<<endl<<"===User Testing==="<<endl;
    u1.getAccount().login("password");
    u1.getAccount().login("password");
    u1.getAccount().login("password");      // should be locked after 3 wrong attempts
    u1.getAccount().login("fhaa123");       // should fail to login due to being locked
    u2.getAccount().login("hehe123");       // should login
    u2.viewProfile();
    
    // Admin Panel
    cout<<endl<<"===Admin Testing==="<<endl;
    // Creating the admin using your custom key
    Admin a1("Admin Khan", "A001", "admin@khi.com", acc1, 4, "FOODHEHE");
    a1.approveListing(&l1);
    a1.unlockUser(u1); 						  // unlocking u1
    a1.resetUserPassword(u2, "meowmeow");    // resetting u2 password
    u1.getAccount().login("fhaa123");       // should be unlocked now and successfully login
    u2.getAccount().login("hehe123");       // wrong password (updated)
    u2.getAccount().login("meowmeow");      // should login
    a1.viewProfile();                       // Display admin profile stats
    cout<<endl;
    cout<<"Total no. of admins online: "<<Admin::getActiveAdmins()<<endl;
    
    // Message
    cout<<endl<<"===Message Testing==="<<endl;
    Message m1("S0667", "S0889", "Is this still available? I have urgent cash.", "11:40 PM", 1);
    Message m2 ("S0889", "S0667", "Hehe wozzap?", "03:07 AM", 1);
    cout<<"Preview: "<<m1.getPreview()<<endl;  //Text preview
    m1.upgradeIfUrgent();           // Should upgrade priority to 3 because of keywords
    m1.displayMessage();            // Should mark as read
    cout<<"Message Status: "<<m1.getStatus()<<endl;
	if (m1 > m2) { 
	    cout << "Message 1 is higher priority!" << endl; 
	}
    
    // Marketplace
    cout<<endl<<"===Marketplace Testing==="<<endl;
    khiMarket.displayMarketStats();
    cout<<"Total website traffic: "<<Marketplace::getTotalVisits()<<endl;

    return 0;
}
