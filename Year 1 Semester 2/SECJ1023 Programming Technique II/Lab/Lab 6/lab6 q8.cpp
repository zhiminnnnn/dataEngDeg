#include <iostream>
using namespace std;

class Contact{
	private:
		string phone;
	public:
		Contact(string p=""){
			phone = p;
		}
		string getPhone(){
			return phone;
		}
};

class Car{
	private:
		string plate;
	public:
		Car(string p=""){
			plate = p;
		}
		string getPlate(){
			return plate;
		}
};

class Customer{
	private:
		string name;
		Contact contact;
		Car *car;
	public:
		Customer(string n="", string p="", Car *c = NULL){
			name = n;
			contact = Contact(p);
			if(c != NULL) car = c;
			else car = NULL;
		}
		string getName(){
			return name;
		}
		string getPhoneNum(){
			return contact.getPhone();
		}
		string getCarPlate(){
			if(car != NULL) return car->getPlate();
			return "";
		}
};

int main(){
	Car car("JSQ245");
	Customer customer[2] = {Customer("Ahmad Kamal", "015-75769800", &car),
							Customer("Siti Nurdiana Abdullah", "014-8889900", NULL)};
	for(int i=0; i<2; i++){
		cout << "Customer's Name: " << customer[i].getName() << endl;
		cout << "Phone Number   : " << customer[i].getPhoneNum() << endl;
		cout << "Rented Car     : " << customer[i].getCarPlate() << endl << endl;
	}
	return 0;
}
