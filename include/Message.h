#pragma once
#include <iostream>
#include <string>
using namespace std;

class Message {
    string senderID;
    string receiverID;
    string textContent;
    string timestamp;
    bool isRead;
    int messagePriority;

public:
    // Parameterized Constructor (Text should have some content)
    Message(string s, string r, string text, string time, int priority);
    
    //Destructor
    ~Message();

    // Member Functions
    void displayMessage();
    string getPreview() const;
    void upgradeIfUrgent();
    string getStatus() const;

	// Getters
	string getSender() const { return senderID; }
	string getReceiver() const { return receiverID; }
	int getPriority() const { return messagePriority; }

    // Declaration: Operator Overloading (>) to compare priority of messages
    bool operator > (const Message& other) const;
};
