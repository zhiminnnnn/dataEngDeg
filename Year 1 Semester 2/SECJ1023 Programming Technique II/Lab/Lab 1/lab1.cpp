//Cheng Zhi Min A25CS0050
//Ng Xuan Yee A25CS0291
//Lab Exercise 1
//Date: 6-4-2026

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int MAX_ITEMS = 3;

class ShoppingCart{
	private:
		string itemNames[MAX_ITEMS];
		double itemPrices[MAX_ITEMS];
		int itemQty[MAX_ITEMS];
	public:
		void setItem(int, string, double, int);
		string getName(int) const;
		double getPrice(int) const;
		int getQty(int) const;
		double calculateTotal() const;
		bool isEligibleForDiscount() const;
		void displayCart() const;
};

void ShoppingCart::setItem(int index, string name, double price, int qty){
	if(price<=0){
		cout << "Invalid price. Price must be greater than RM0.00." << endl;
		exit(0);
		return;
	}
	if(qty<=0){
		cout << "Invalid quantity. Quantity must be at least 1." << endl;
		return;
	}
	itemNames[index] = name;
	itemPrices[index] = price;
	itemQty[index] = qty;
}

string ShoppingCart::getName(int index) const{
	return itemNames[index];
}

double ShoppingCart::getPrice(int index) const{
	return itemPrices[index];
}

int ShoppingCart::getQty(int index) const{
	return itemQty[index];
}

double ShoppingCart::calculateTotal() const{
	double sum = 0;
	for(int i=0; i<MAX_ITEMS; i++){
		sum += itemQty[i] * itemPrices[i];
	}
	return sum;
}

bool ShoppingCart::isEligibleForDiscount() const{
	return calculateTotal()>=50;
}

void ShoppingCart::displayCart() const{
	double disc;
	if(isEligibleForDiscount()) disc = 0.1;
	
	else disc = 0;
	
	cout << fixed << setprecision(2);
	cout << "=============== Cart Receipt ==============="<<endl;
	cout << left << setw(14) << "Item"
		 << right<< setw(10) << "Price" 
				 << setw(10) << "Qty" 
				 << setw(10) << "Subtotal" << endl;
	cout << "--------------------------------------------" << endl;
	
	for(int i=0; i<MAX_ITEMS; i++){
	cout << left << setw(14) << itemNames[i]
		 << right<< setw(10) << itemPrices[i]
			     << setw(10) << itemQty[i] 
			     << setw(10) << getPrice(i) * getQty(i) << endl;
	}
	
	cout << "--------------------------------------------" << endl;

	cout << "Total before discount:          RM " << left << calculateTotal() << endl;
	cout << "Discount (10%):                -RM " << calculateTotal() * disc << endl;
	cout << "Final Total:                    RM " << calculateTotal() - disc << endl;
	cout << "============================================" << endl;
}
	
int main(){
	
	string n;
	int q;
	double p;
	
	ShoppingCart s;
	
	for(int i=0; i<MAX_ITEMS; i++){
		cout << "Enter item " << i+1 << " name: ";
		cin >> n;
		cout << "Enter item " << i+1 << " price: ";
		cin >> p;
		cout << "Enter item " << i+1 << " quantity: ";
		cin >> q;
		s.setItem(i, n, p, q);
	}
	
	cout << endl;
		
	if(s.isEligibleForDiscount())
		cout << "You qualify for a 10% discount!" << endl;
	else
		cout << "No discount applied." << endl;
	
	cout << endl;
	
	s.displayCart();
	
	return 0;
}