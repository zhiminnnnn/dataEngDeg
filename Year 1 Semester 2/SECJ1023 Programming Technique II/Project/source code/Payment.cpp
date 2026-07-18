#include "Payment.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

Payment::Payment(double a) { amount = a; }

//prompts user to choose from three options
void Payment::selectPaymentMethod() {
    int choice;
    cout << "\n1. Card | 2. E-Wallet | 3. Cash\nSelect Payment: ";
    cin >> choice;
    //If Card is selected, asks for card number.
    if(choice == 1) {
		method = "Card";
		cout << "Card No: ";
		cin >> details;
	}
	//If E-Wallet is selected, asks for Wallet ID
    else if(choice == 2) {
		method = "E-Wallet";
		cout << "Wallet ID: ";
		cin >> details;
	}
    else {
    	//Cash no additional input
		method = "Cash";
		details = "N/A"; }
    cout << endl;
}

//prints confirmation message showing amount and method
bool Payment::process() {
    cout << ">> Paying RM" << amount << " via " << method << "... Done!" << endl;
    return true; //signal success
}

string Payment::getMethod() const { return method; }