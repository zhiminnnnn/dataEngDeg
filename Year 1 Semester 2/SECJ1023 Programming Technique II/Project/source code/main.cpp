#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "FoodOrderingSystem.h"
using namespace std;

int main() {
    FoodOrderingSystem system;
    int choice;
    while(true) {
        cout << "\n--- FOODIE DELIVERY ---" << endl;
        cout << "1. Order Menu" << endl;
        cout << "2. Payment & Checkout" << endl;
        cout << "3. Live Tracking" << endl;
        cout << "4. Give Feedback" << endl;
        cout << "5. View All Feedbacks" << endl;
        cout << "6. Exit" << endl << endl;
        cout << "Selection: ";
        if(!(cin >> choice)) {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Please enter a valid number." << endl;
            continue;
        }
        switch(choice) {
            case 1: system.startOrdering(); break;
            case 2: system.doCheckout(); break;
            case 3: system.trackOrders(); break;
            case 4: system.addFeedback(); break;
            case 5: system.showFeedbacks(); break;
            case 6:
                cout << "\nExiting system... Have a nice day!" << endl;
                return 0;
            default:
                cout << "\nInvalid choice! Try again." << endl;
        }
    }
    return 0;
}