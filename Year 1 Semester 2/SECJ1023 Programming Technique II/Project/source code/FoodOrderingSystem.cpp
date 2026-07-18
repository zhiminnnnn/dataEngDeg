#include "FoodOrderingSystem.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

//constructor calls initializeMenu()
//allocates 16 FoodItem objects and 4 DrinkItem objects.
FoodOrderingSystem::FoodOrderingSystem()
    : menuCount(0), orderCount(0), feedbackCount(0), current(nullptr) {
    for(int i = 0; i < MAX_ORDERS; i++) history[i] = nullptr;
    for(int i = 0; i < MAX_MENU * 2; i++) menu[i] = nullptr;
    srand(time(0));
    initializeMenu();
}

//destructor loops through all three arrays
//deletes every allocated object
FoodOrderingSystem::~FoodOrderingSystem() {
    for(int i = 0; i < orderCount; i++)
		delete history[i];
    for(int i = 0; i < menuCount; i++)
		delete menu[i];
    if(current)
		delete current;
}

void FoodOrderingSystem::initializeMenu() {
    menu[menuCount++] = new FoodItem(1,  "Beef Burger Special",       12.00, "Main");
    menu[menuCount++] = new FoodItem(2,  "Char Kuey Teow",            7.00,  "Main");
    menu[menuCount++] = new FoodItem(3,  "Chicken Pizza (R)",         12.00, "Main");
    menu[menuCount++] = new FoodItem(4,  "Chicken Rice",              9.00,  "Main");
    menu[menuCount++] = new FoodItem(5,  "Nasi Lemak Chicken",        7.50,  "Main");
    menu[menuCount++] = new FoodItem(6,  "Penang Hokkien Mee",        7.00,  "Main");
    menu[menuCount++] = new FoodItem(7,  "Penang Laksa",              7.00,  "Main");
    menu[menuCount++] = new FoodItem(8,  "Wonton Noodle Soup",        8.50,  "Main");
    menu[menuCount++] = new FoodItem(9,  "Cheesy Fries",              5.50,  "Snack");
    menu[menuCount++] = new FoodItem(10, "Curry Puff Sardin (2 pcs)", 4.00,  "Snack");
    menu[menuCount++] = new FoodItem(11, "Fried Chicken (2 pcs)",     7.00,  "Snack");
    menu[menuCount++] = new FoodItem(12, "Roti Canai",                3.50,  "Snack");
    menu[menuCount++] = new FoodItem(13, "Tosai",                     4.50,  "Snack");
    menu[menuCount++] = new FoodItem(14, "Apam Balik (2 pcs)",        4.00,  "Dessert");
    menu[menuCount++] = new FoodItem(15, "Burnt Cheese Cake (1 pcs)", 7.00,  "Dessert");
    menu[menuCount++] = new FoodItem(16, "Sundae Cone",               4.00,  "Dessert");
    menu[menuCount++] = new DrinkItem(17, "Cendol",          4.00, true);
    menu[menuCount++] = new DrinkItem(18, "Iced Lemon Tea",  4.00, true);
    menu[menuCount++] = new DrinkItem(19, "Teh Tarik Ais",   3.00, true);
    menu[menuCount++] = new DrinkItem(20, "Teh Tarik Panas", 3.00, false);
}

void FoodOrderingSystem::displayMenu() {
    cout << "\n======================== MENU ========================" << endl;
    for(int i = 0; i < menuCount; i++)
		menu[i]->display(); //C++ automatically calls the correct
		                    //overridden version at runtime
    cout << endl;
}

void FoodOrderingSystem::startOrdering() {
	if (current && current->getTotal() > 0) {
        cout << "\nYou have an active order. (C)ontinue or (N)ew? ";
        char c;
		cin >> c;

        if (c == 'N' || c == 'n') {
            delete current;
            current = new Order();
        }
    }
	else if (!current)
        current = new Order();

    displayMenu();

    while(true) {
        int id, qty;
        cout << "Enter Menu ID (0 to stop): ";
        cin >> id;
        
        if(id == 0)
			break;

		bool found = false;

		for(int i = 0; i < menuCount; i++) {
    		if(menu[i]->getId() == id) {
	        	do {
	            	cout << "Qty: ";
					cin >> qty;
	            	if(qty <= 0)
						cout << "[!] Invalid quantity." << endl << endl;
	        	} while(qty <= 0);

	        	current->addOrMergeItem(menu[i]->getName(), menu[i]->getPrice(), qty);
	        	found = true;
	        	break;
    		}
		}
        if(!found)
			cout << "[!] Invalid Food ID" << endl << endl;
    }
}

void FoodOrderingSystem::doCheckout() {
    if(!current || current->getTotal() == 0) {
        cout << "\n[!] Please order something first." << endl;
        return;
    }
    CustomerInfo info;
    info.inputInfo();
    current->setCustomerInfo(info);
    if(current->checkout()) {
        history[orderCount++] = current;
        cout << "\n[Success] Receipt Generated:" << endl;
        history[orderCount-1]->display(true);
        current = nullptr;
    }
}

void FoodOrderingSystem::trackOrders() {
    if(orderCount == 0) {
		cout << "\n[!] No active delivery." << endl;
		return;
	}
    cout << "\n======= LIVE TRACKING =======" << endl;
    for(int i = 0; i < orderCount; i++) {
        history[i]->updateTracking();
        history[i]->display(true);
    }
}

void FoodOrderingSystem::addFeedback() {
    if (orderCount == 0) {
        cout << "\n[!] No orders to rate." << endl;
        return;
    }
	//shows all past orders tagged as Rated or Not Rated
    cout << "\n===== YOUR ORDERS =====" << endl;
    for (int i = 0; i < orderCount; i++) {
        int oid = history[i]->getOrderId();
        bool rated = false;
        for (int j = 0; j < feedbackCount; j++) {
            if (feedbacks[j].getId() == oid) {
                rated = true;
                break;
            }
        }
        cout << "  Order #" << oid << (rated ? "  [Rated]" : "  [Not Rated]") << endl;
    }
    int oid;
    cout << "\nEnter Order ID to rate (0 to cancel): ";
    cin >> oid;
    if (oid == 0)
		return;
	//validates Order ID entered
    bool found = false;
    for (int i = 0; i < orderCount; i++) {
        if (history[i]->getOrderId() == oid) {
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "[!] Order #" << oid << " not found." << endl;
        return;
    }
    for (int i = 0; i < feedbackCount; i++) {
    	//checks whether that order has been rated
        if (feedbacks[i].getId() == oid) {
            cout << "[!] You have already rated order #" << oid << "." << endl;
            return;
        }
    }
    //creates new Feedback object and adds it to feedbacks[] only if both checks pass.
    Feedback fb(oid);
    fb.input();
    feedbacks[feedbackCount++] = fb;
    cout << "[Success] Feedback submitted for Order #" << oid << "!" << endl;
}

void FoodOrderingSystem::showFeedbacks() {
    if(feedbackCount == 0)
		cout << "\n[!] No feedback yet." << endl;
    for(int i = 0; i < feedbackCount; i++)
		feedbacks[i].display();
}