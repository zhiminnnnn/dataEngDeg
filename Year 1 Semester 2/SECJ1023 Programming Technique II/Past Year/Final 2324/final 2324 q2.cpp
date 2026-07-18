#include <iostream>
#include <vector>
using namespace std;

class FoodItem{
	protected:
		string name;
		double price;
		int quantity;
	public:
		FoodItem(string name="", double price=0, int quantity=0){
			this->name = name;
			this->price = price;
			this->quantity = quantity;
		}
		virtual void dispDetails() = 0;
		virtual double calcPrice(){
			return price * quantity;
		}
};

class Pizza : public FoodItem{
	private:
		string size;
	public:
		Pizza(string name="", double price=0, string size="", int quantity=0) : FoodItem(name, price, quantity){
			this->size = size;
		}
		void dispDetails(){
			cout << "Pizza - " << name << endl;
			cout << "Price: RM" << price << endl;
			cout << "Quantity: " << quantity << endl;
			cout << "Size: " << size << endl << endl;
		}
};

class Burger : public FoodItem{
	private:
		bool isDoublePatty;
	public:
		Burger(string name="", double price=0, bool isDoublePatty=0, int quantity=0) : FoodItem(name, price, quantity){
			this->isDoublePatty = isDoublePatty;
		}
		void dispDetails(){
			cout << "Burger - " << name << endl;
			cout << "Price: RM" << price << endl;
			cout << "Quantity: " << quantity << endl;
			cout << "Double Patty: ";
			if(isDoublePatty) cout << "Yes";
			else cout << "No";
			cout << endl << endl;
		}
		double calcPrice(){
			if(isDoublePatty) return FoodItem::calcPrice() + 3.8;
			return FoodItem::calcPrice();
		}
};

class Order{
	private:
		vector <FoodItem*> foodItem;
		
	public:
		Order(){}
		void addItem(FoodItem *f){
			foodItem.push_back(f);
		}
		void dispOrder(){
			double sum;
			for(int i=0; i<foodItem.size(); i++){
				sum += foodItem.at(i)->calcPrice();
			}
			if(sum < 20) throw "OrderException: The total order amount is less than RM20.\nTo place an online order, the minimum order amount should be RM20!";
			else{
				for(int i=0; i<foodItem.size(); i++){
					foodItem.at(i)->dispDetails();
				}
				cout << "Total Order Price: RM" << sum << endl;
			}
		}
};

int main(){
	Order order;
	FoodItem *foodItem[5];
	foodItem[0] = new Pizza ("Super Supreme", 52.3, "Large", 1);
	foodItem[1] = new Burger ("Cheeseburger", 14.5, 0, 3);
	foodItem[2] = new Pizza ("Hawaiian Chicken", 19.9, "Personal", 3);
	foodItem[3] = new Pizza ("Beef Pepperoni", 40.9, "Regular", 1);
	foodItem[4] = new Burger ("Chicken", 13.5, 1, 2);
	for(int i=0; i<5; i++){
		order.addItem(foodItem[i]);
	}
	try{
		order.dispOrder();
	}
	catch(const char *msg){
		cout << msg;
	}
	return 0;
}