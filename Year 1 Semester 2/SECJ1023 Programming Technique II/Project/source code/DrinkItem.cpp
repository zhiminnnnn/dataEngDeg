#include "DrinkItem.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

DrinkItem::DrinkItem() : MenuItem() { isCold = false; }

DrinkItem::DrinkItem(int i, string n, double p, bool cold) : MenuItem(i, n, p) {
    isCold = cold;
}

bool DrinkItem::getIsCold() const { return isCold; }

void DrinkItem::display() const {
    cout << "  " << setw(2) << id << ". " << left << setw(26) << name
         << "RM" << fixed << setprecision(2) << right << setw(6) << price
         << "  [Drink - " << (isCold ? "Cold" : "Hot") << "]" << endl;
}        //display() override uses a ternary operator to print the drink type