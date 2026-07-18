#ifndef FOOD_ORDERING_SYSTEM_H
#define FOOD_ORDERING_SYSTEM_H
#include <string>
#include "FoodItem.h"
#include "DrinkItem.h"
#include "Order.h"
#include "Feedback.h"

using namespace std;

const int MAX_MENU = 50;
const int MAX_ORDERS = 50;
const int MAX_FEEDBACKS = 50;

class FoodOrderingSystem {
    private:
        MenuItem* menu[MAX_MENU * 2]; //pointer array holding 20 menu items on heap
	    int menuCount;
	    Order* history[MAX_ORDERS]; //pointer array for all completed orders
	    int orderCount;
	    Feedback feedbacks[MAX_FEEDBACKS]; //value array for all submitted feedback
	    int feedbackCount;
	    Order* current; //pointer to in-progress order, nullptr if none
    public:
        FoodOrderingSystem();
        ~FoodOrderingSystem();
        void initializeMenu();
        void displayMenu();
        void startOrdering();
        void doCheckout();
        void trackOrders();
        void addFeedback();
        void showFeedbacks();
};

#endif