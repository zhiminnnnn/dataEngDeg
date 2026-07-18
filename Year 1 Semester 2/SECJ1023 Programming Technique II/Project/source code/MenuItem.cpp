#include "MenuItem.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

MenuItem::MenuItem() {
	id = 0;
	name = "";
	price = 0;
}

MenuItem::MenuItem(int i, string n, double p) {
	id = i;
	name = n;
	price = p;
}

int MenuItem::getId() const { return id; }

string MenuItem::getName() const { return name; }

double MenuItem::getPrice() const { return price; }

void MenuItem::display() const {
    cout << "  " << setw(2) << id << ". " << left << setw(26) << name
         << "RM" << fixed << setprecision(2) << right << setw(6) << price << endl;
}