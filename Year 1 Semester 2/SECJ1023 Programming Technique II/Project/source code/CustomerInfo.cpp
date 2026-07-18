#include "CustomerInfo.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

CustomerInfo::CustomerInfo() {
	name = "";
	phone = "";
	address = "";
}

void CustomerInfo::inputInfo() {
    cout << "\n========== DELIVERY INFORMATION ==========" << endl;
    cout << "Receiver Name: ";
	cin.ignore();
	getline(cin, name); //allow spaces
	
    cout << "Phone Number : ";
	getline(cin, phone);
	
    cout << "Address      : ";
	getline(cin, address);
}

//prints details neatly onto receipt
void CustomerInfo::display() const {
    cout << "Customer: " << name << endl;
    cout << "Contact : " << phone << endl;
    cout << "Address : " << address << endl << endl;
}

string CustomerInfo::getName() const { return name; }