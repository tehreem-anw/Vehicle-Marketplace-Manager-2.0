#pragma once
#include <iostream>
#include <string>
#include "Account.h"
using namespace std;

class Admin;

class User {
protected:
    string name;
    const string userID; // Constant Member
    string email;
    bool isActive;
    Account acc; // Composition
    static int totalUsers; // Static Member 

public:
    // Parameterized Constructor (Account base class)
    User(string n, string id, string e, Account a);
    
    // Virtual destructor for inheritance safety
	virtual ~User(); 

	friend class Admin;

    // Pure Virtual Function - Makes class Abstract
    virtual void viewProfile() const = 0;

    // Member Functions
    void updateEmail(string newEmail);
    void toggleStatus();
    bool validateID(string inputID) const;
    static int getTotalUsers(); // Static Member Function
    
    // Friend Function
    friend void systemAudit(const User& u);

    // Declaration: Operator Overloading (==)
    bool operator == (const string& checkID) const;

    // Getters
    Account& getAccount() { return acc; }
    string getUserID() const { return userID; }
};
