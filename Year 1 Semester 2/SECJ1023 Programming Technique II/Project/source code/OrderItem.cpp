#include "OrderItem.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

OrderItem::OrderItem() {
	itemName = "";
	itemPrice = 0;
	quantity = 0;
}

OrderItem::OrderItem(string n, double p, int q) {
    itemName = n;
    itemPrice = p;
    quantity = q;
}

string OrderItem::getItemName() const { return itemName; }

double OrderItem::getSubtotal() const { return itemPrice * quantity; }

void OrderItem::addQuantity(int q) { quantity += q; }
// only way to increase the quantity

void OrderItem::printLine() const {
    cout << left << setw(25) << itemName << " x " << quantity
         << " = RM " << fixed << setprecision(2) << getSubtotal() << endl;
}

int OrderItem::getQuantity() const { return quantity; }