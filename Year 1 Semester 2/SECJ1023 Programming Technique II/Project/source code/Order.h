#ifndef ORDER_H
#define ORDER_H
#include <string>
#include "CustomerInfo.h"
#include "OrderItem.h"
#include "Payment.h"
using namespace std;

const int MAX_ORDER_ITEMS = 50;

//manages an entire customer transaction from start to finish.
class Order {
    private:
        static int nextId; //counter that auto-increments for every new order, starting from 1001
        int orderId;
        CustomerInfo customer; //delivery details, stored by value (composition)
        OrderItem items[MAX_ORDER_ITEMS]; //array of ordered items, by value (composition)
        int itemCount;
        double total;
        string deliveryStatus;
        Payment* payRecord; //pointer to Payment object, created only during checkout
    public:
        Order();
        ~Order();
        void setCustomerInfo(CustomerInfo info);
		bool addOrMergeItem(string name, double price, int q);
        bool checkout();
        void updateTracking();
        void display(bool showTracking = false) const;
        int getOrderId() const;
        double getTotal() const;
};

#endif