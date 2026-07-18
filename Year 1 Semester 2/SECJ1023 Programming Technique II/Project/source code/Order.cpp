#include "Order.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

Order::Order() {
    itemCount = 0;
	total = 0;
    deliveryStatus = "Preparing";
    payRecord = nullptr;
    orderId = nextId++;
}

//destructor calls delete payRecord to free memory
Order::~Order() { delete payRecord; }

//Once checkout done, CustomerInfo object is stored inside Order object
void Order::setCustomerInfo(CustomerInfo info) { customer = info; } //composition

bool Order::addOrMergeItem(string name, double price, int q) {
	//searches existing items array for item with same name
    for (int i = 0; i < itemCount; i++) {
        if (items[i].getItemName() == name) {
        //If found, calls addQuantity() and updates the total
            items[i].addQuantity(q); //composition
            total += price * q;
            return true;
        }
    }
    //If not, creates new OrderItem entry
    if (itemCount < MAX_ORDER_ITEMS) {
        items[itemCount++] = OrderItem(name, price, q);
        total += price * q;
        return true;
    }
    return false;
}

//creates Payment object on heap, calls selectPaymentMethod(), then calls process().
bool Order::checkout() {
    payRecord = new Payment(total);
    payRecord->selectPaymentMethod();
    return payRecord->process();
    //If successful, Order is moved into history[] array by FoodOrderingSystem.
}

//randomly selects one of four statuses
//simulates live delivery updates every time user checks tracking.
void Order::updateTracking() {
    string statuses[] = {"Preparing", "Kitchen Cooking", "On the way", "Arrived"};
    deliveryStatus = statuses[rand() % 4];
}

void Order::display(bool showTracking) const {
    cout << "\n------------------------------------------" << endl;
    cout << "ORDER ID: #" << orderId << endl;
    if(showTracking)
		cout << "STATUS: [" << deliveryStatus << "]";
    cout << "\n------------------------------------------" << endl;
    customer.display();
    for(int i = 0; i < itemCount; i++)
		items[i].printLine();
    cout << "\nTOTAL: RM " << fixed << setprecision(2) << total << endl;
    cout << "------------------------------------------" << endl;
}

int Order::getOrderId() const { return orderId; }

double Order::getTotal() const { return total; }

int Order::nextId = 1001;