#include "User.h"

// Initialize static member
int User::totalUsers = 0;

// Constructor using Initializer List for the constant userID
User::User(string n, string id, string e, Account a) : name(n), userID(id), email(e), acc(a) {
    isActive = true;
    totalUsers++;
}

User::~User() {
    totalUsers--;
}

void User::updateEmail(string newEmail) {
    email = newEmail;
    cout<<"Email updated to: "<<email<<endl;
}

void User::toggleStatus() {
    isActive = !isActive;
    cout<<"User status changed to: ";
    if(isActive){
    	cout<<"Active"<<endl;
	}
	else{
		cout<<"Inactive"<<endl;
	}
}

bool User::validateID(string inputID) const {
    return userID == inputID;
}

int User::getTotalUsers() {
    return totalUsers;
}

// Implementation: Operator Overloading (==)
bool User::operator == (const string& checkID) const {
    return userID == checkID;
}

// Implementation: Friend Function
void systemAudit(const User& u) {
    cout<<"--- SYSTEM AUDIT ---"<<endl;
    cout<<"User: "<<u.name<<" | ID: "<<u.userID<<" | Email: "<<u.email<<endl;
    cout<<"--------------------"<<endl;
}
