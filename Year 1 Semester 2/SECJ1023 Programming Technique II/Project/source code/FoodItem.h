#ifndef FOODITEM_H
#define FOODITEM_H
#include <string>
#include "MenuItem.h"
using namespace std;

//derived class
class FoodItem : public MenuItem { //inherits publicly
    private:
        string category;
    public:
        FoodItem();
        FoodItem(int i, string n, double p, string c);
        string getCategory() const;
        void display() const;
};

#endif