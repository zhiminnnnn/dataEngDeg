#ifndef ORDERITEM_H
#define ORDERITEM_H
#include <string>
using namespace std;

class OrderItem {
    private: //Nothing outside can modify them directly.
        string itemName;
        double itemPrice;
        int quantity;
    public:
        OrderItem();
        OrderItem(string n, double p, int q);
        string getItemName() const;
        double getSubtotal() const;
        void addQuantity(int q); //key method
        void printLine() const;
        int getQuantity() const;
};

#endif