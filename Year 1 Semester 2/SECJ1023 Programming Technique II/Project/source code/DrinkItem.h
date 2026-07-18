#ifndef DRINKITEM_H
#define DRINKITEM_H
#include <string>
#include "MenuItem.h"
using namespace std;

//derived class
class DrinkItem : public MenuItem {
    private:
        bool isCold; //extra attribute
    public:
        DrinkItem();
        DrinkItem(int i, string n, double p, bool cold);
        bool getIsCold() const;
        void display() const;
};

#endif