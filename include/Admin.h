#pragma once
#include "User.h"

class Listing;
class Admin : public User {
    int accessLevel;             // 1-5
    string lastActionPerformed;	 // Approved/Deleted ad
    int totalApprovals;
    int totalRemovals;
    const string adminKey;       // CONSTANT MEMBER
    static int activeAdmins;     // STATIC MEMBER

public:
    // Parameterized Constructor (User base class)
    Admin(string n, string id, string e, Account a, int level, string key);
    // Destructor
    ~Admin();

    // Overriding Pure Virtual Function
    void viewProfile() const override;

    // Member Functions
    void approveListing(Listing* l);
    void unlockUser(User& u);
    void resetUserPassword(User& u, string newPass);
    static int getActiveAdmins();

    // Declaration: Operator Overloading (==) to compare admin seniority
    bool operator == (const Admin& other) const;
    // Declaration: Operator Overloading (+) to combine approval stats
    int operator + (const Admin& other) const;
};
