#include "Feedback.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

Feedback::Feedback() {
	id = 0;
	rate = 0;
}

Feedback::Feedback(int oid) { id = oid; }

int Feedback::getId() const { return id; }

//prompts the user for rating and comment
void Feedback::input() {
    cout << "Rating (0-5): ";
	cin >> rate;
	
    cout << "Comment: ";
	cin.ignore();
	getline(cin, msg);
}

//prints the Order ID, star count, and comment in one line.
void Feedback::display() const {
    cout << "Order #" << id << " -> " << rate << " stars: " << msg << endl;
}