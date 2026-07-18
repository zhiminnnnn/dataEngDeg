#include <iostream>
#include <vector>
using namespace std;

class Product{
	protected:
		string name;
		double price;
		int quantity;
	public:
		Product(string name="", double price=0, int quantity=0){
			this->name = name;
			this->price = price;
			this->quantity = quantity;
		}
		virtual void display() const = 0;
		virtual double calculateTotal() const{
			return price * quantity;
		}
		~Product(){}
};

class ElectronicProduct : public Product{
	private:
		int warranty;
	public:
		ElectronicProduct(string name="", double price=0, int quantity=0, int warranty=0) : Product(name, price, quantity){
			this->warranty = warranty;
		}
		void display() const{
			cout << "Electronic: " << name << endl;
			cout << "Price: RM" << price << endl;
			cout << "Quantity: " << quantity << endl;
			cout << "Warranty: " << warranty << " months" << endl << endl;
		}
};

class ClothingProduct : public Product{
	private:
		string size;
	public:
		ClothingProduct(string name="", double price=0, int quantity=0, string size="") : Product(name, price, quantity){
			this->size = size;
		}
		void display() const{
			cout << "Clothing: " << name << endl;
			cout << "Price: RM" << price << endl;
			cout << "Quantity: " << quantity << endl;
			cout << "Size: " << size << " months" << endl << endl;
		}
};

class ShoppingCart{
	public:
		vector <Product*> items;
		void addProduct(Product *p){
			items.push_back(p);
		}
		void displayCart() const{
			if(calculateTotal() < 100) throw "LowTotalException: Your order must be at least RM100 to proceed.";
			else{
				for(int i=0; i<items.size(); i++){
					items.at(i)->display();
				}
				cout << "Total Amount: RM" << calculateTotal() << endl;
				int count=0;
				for(int i=0; i<items.size(); i++){
					if(items.at(i)->calculateTotal() > 50) count ++;
				}
				cout << "Number of products above RM50: " << count << endl;
			}
		}
		double calculateTotal() const{
			double sum = 0;
			for(int i=0; i<items.size(); i++){
				sum += items.at(i)->calculateTotal();
			}
			return sum;
		}
		~ShoppingCart(){
			for(int i=0; i<items.size(); i++){
				delete items.at(i);
			}
		}
};

int main(){
	ShoppingCart c;
	Product *p[2];
	p[0] = new ElectronicProduct("Smart Watch", 120, 1, 24);
	p[1] = new ClothingProduct("T-Shirt", 35, 2, "L");
	c.addProduct(p[0]);
	c.addProduct(p[1]);
	try{
		c.displayCart();
	}
	catch(const char *msg){
		cout << msg;
	}
	return 0;
}