#include "FoodItem.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

FoodItem::FoodItem() : MenuItem() { category = ""; }

FoodItem::FoodItem(int i, string n, double p, string c) : MenuItem(i, n, p) {
    category = c;                						  //initialiser list                                             
	                                                      //- avoids duplicating logic                    
														  //  for setting attributes
}

string FoodItem::getCategory() const { return category; }

void FoodItem::display() const {
    cout << "  " << setw(2) << id << ". " << left << setw(26) << name
         << "RM" << fixed << setprecision(2) << right << setw(6) << price
         << "  [Food - " << category << "]" << endl;
		 //display() override prints category
}