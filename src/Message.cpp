#include "Message.h"

// Parameterized Constructor
Message::Message(string s, string r, string text, string time, int priority)
    : senderID(s), receiverID(r), textContent(text), timestamp(time), isRead(false), messagePriority(priority) {}

Message::~Message() {
}

// Function 1: Display with Read-Status Update
void Message::displayMessage() {
    isRead = true;
    cout<<"["<<timestamp<<"] From: "<<senderID<<" | Priority: "<<messagePriority<<endl;
    cout<<"Content: "<<textContent<<endl;
    cout<<"Status: "<<getStatus()<<endl;
}

// Function 2: Preview Generator (Logic for Inbox/Notification View)
string Message::getPreview() const {
    if(textContent.length()>15) {
        return textContent.substr(0,15) + "...";
    }
    return textContent;
}

// Function 3: Urgency Upgrader
void Message::upgradeIfUrgent() {
    // Check for urgent keywords (case sensitive check)
    if(textContent.find("urgent") != string::npos || textContent.find("cash") != string::npos) {
        messagePriority=3;
        cout<<"Priority upgraded based on keywords."<<endl;
    }
}

// Function 4: View Status (Update Read)
string Message::getStatus() const {
	if(isRead){
	    return "Seen";
	}
	else{
		return "Not Seen";
	}
}

// Implementation: Operator Overloading (>)
bool Message::operator > (const Message& other) const {
    return messagePriority > other.messagePriority;
}
