#ifndef MENUITEM_H
#define MENUITEM_H
#include <string>
using namespace std;

//base class
class MenuItem {
    protected: //derived classes can inherit
        int id;
        string name;
        double price;
    public:
        MenuItem();
        MenuItem(int i, string n, double p);
        int getId() const;
        string getName() const;
        double getPrice() const;
        virtual void display() const;       //virtual
        virtual ~MenuItem() {}   	        //virtual - when delete a MenuItem* pointer that points to FoodItem/DrinkItem,
		                                    //          C++ calls the correct derived destructor.
};

#endif