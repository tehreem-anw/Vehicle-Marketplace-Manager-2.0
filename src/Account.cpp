#include "Account.h"

// Default Constructor
Account::Account() : accountID(0), username("Guest"), password(""), dateCreated("N/A"), failedAttempts(0), isLocked(false) {}

// Parameterized Constructor
Account::Account(int id, string user, string pass, string date): accountID(id), username(user), password(pass), dateCreated(date), failedAttempts(0), isLocked(false) {}

void Account::login(string inputPass) {
    if(isLocked){
        cout<<"Account is locked. Please contact Admin."<<endl;
        return;
    }
    // Impementation: Operator Overloading (==)
    if(*this == inputPass){
        cout<<"Login Successful!"<<endl;
        failedAttempts = 0;
    }else{
        failedAttempts++;
        cout<<"Incorrect password. Attempt: "<<failedAttempts<<endl;
        if(failedAttempts >= 3){
            isLocked = true;
            cout<<"Account has been locked due to security reasons."<<endl;
        }
    }
}

void Account::resetPassword(string newPass) {
    if(newPass.length()<6){
        cout<<"Error: Password too short."<<endl;
    }else{
        password = newPass;
        cout<<"Password updated successfully."<<endl;
    }
}

void Account::displayAccountInfo() const {
    cout<<"Account ID: "<<accountID<<" | User: "<<username<<endl;
	cout<<"Created on: "<<dateCreated<<" | Status: ";
	if(isLocked){
		cout<<"Locked"<<endl;
	}
	else{
		cout<<"Active"<<endl;
	}
}

void Account::unlockAccount() {
    isLocked = false;
    failedAttempts = 0;
}

// Definition: Operator Overloading (==)
bool Account::operator == (const string& inputPass) const {
    return password == inputPass;
}
