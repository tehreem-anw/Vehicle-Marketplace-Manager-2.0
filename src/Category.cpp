#include "Category.h"

// Default Constructor (Safety fallback only)
Category::Category() : typeName("NA"), licenseRequired("NA"), baseTaxRate(0.00), isCommercial(false) {}

// Parameterized Constructor: Uses Initializer List for Const member
Category::Category(string name, string license, double tax, bool comm)
    : typeName(name), licenseRequired(license), baseTaxRate(tax), isCommercial(comm) {}

Category::~Category() {
}

// Function 1: Display Legal/Tax Details
void Category::displayCategory() const {
    cout<<"---[CATEGORY DETAILS]---"<<endl;
    cout<<"Class: "<<typeName<<" | Required License: "<<licenseRequired<<endl;
    cout<<"Usage: "<<(isCommercial ? "Commercial" : "Personal")<<" | Base Tax: "<<(baseTaxRate * 100)<<"%"<<endl;
}

// Function 2: Tax Calculation
double Category::calculateTax(double price) const {
    double totalRate = baseTaxRate;
    if(isCommercial) {
        totalRate += 0.05; // 5% extra for commercial
    }
    return price * totalRate;
}

// Function 3: License Validation
bool Category::checkLicenseMatch(string userLicense) const {
    return (userLicense == licenseRequired);
}
