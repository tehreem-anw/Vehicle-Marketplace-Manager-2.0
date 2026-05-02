#pragma once
#include <iostream>
#include <string>
using namespace std;

class Listing;

class Account {
    string username;
    string password;
    const int accountID;
    string dateCreated;
    int failedAttempts;
    bool isLocked;
public:
	// Constructors
	Account();
	// Parameterized Constructor (Account should have ID, user name, password)
	Account(int id, string user, string pass, string date);
	
	// Member Functions
	void login(string inputPass);
	void resetPassword(string newPass);
	void displayAccountInfo() const;
	void unlockAccount();
	
	// Declaration: Operator Overloading (==) to compare password
	bool operator == (const string& inputPass) const;
};
