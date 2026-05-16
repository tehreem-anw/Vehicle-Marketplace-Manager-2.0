#include "Admin.h"
#include "Listing.h"

// Initialize static member
int Admin::activeAdmins = 0;

// Constructor: Chaining User and initializing Admin-specific constants
Admin::Admin(string n, string id, string e, Account a, int level, string key) 
    : User(n, id, e, a), adminKey(key), accessLevel(level), totalApprovals(0), totalRemovals(0), lastActionPerformed("None") {
    activeAdmins++;
}

Admin::~Admin() {
    activeAdmins--;
}

// Overriding Pure Virtual Function
void Admin::viewProfile() const {
    cout<<"---[ADMIN PROFILE]---"<<endl;
    cout<<"Admin Key: "<<adminKey<<" | Level: "<<accessLevel<<endl;
    cout<<"Name: "<<name<<" | ID: "<<userID<<endl;
    cout<<"Email: "<<email<<endl;
    cout<<"Actions: "<<totalApprovals<<" Approvals | "<<totalRemovals<<" Removals"<<endl;
    cout<<"Last Action: "<<lastActionPerformed<<endl;
    cout<<"-----------------------"<<endl;
}

// Function 1: Approve a Listing
void Admin::approveListing(Listing* l) {
    if(l == nullptr) return;
    if(accessLevel >= 2) {
        l->status = "Approved"; // Can access private member status directly
        totalApprovals++;
        lastActionPerformed = "Approved Listing: " + to_string(l->getID());
        cout<<"Listing "<<l->getID()<<" approved successfully by "<<name<<"."<<endl;
    } else {
        cout<<"Access Denied: Level 2 required for approvals."<<endl;
    }
}

// Function 2: Unlock User Account
void Admin::unlockUser(User& u) {
    u.acc.unlockAccount(); 			// Can access private acc member directly
    lastActionPerformed = "Unlocked User: " + u.userID;
    cout<<"User ["<<u.userID<<"] has been manually unlocked."<<endl;
}

// Function 3: Reset User Password
void Admin::resetUserPassword(User& u, string newPass) {
    if(accessLevel >= 4) {
        u.getAccount().resetPassword(newPass);
        lastActionPerformed = "Reset Password for: " + u.getUserID();
        cout<<"Password reset successful for user: "<<u.getUserID()<<endl;
    } else {
        cout<<"Access Denied: Level 4 required for security resets."<<endl;
    }
}

// Function 4: Static Function to check total admins
int Admin::getActiveAdmins() {
    return activeAdmins;
}

// Definition: Operator Overloading (==)
bool Admin::operator == (const Admin& other) const {
    return (accessLevel == other.accessLevel);
}

// Definition: Operator Overloading (+)
int Admin::operator + (const Admin& other) const {
    return totalApprovals + other.totalApprovals;
}
