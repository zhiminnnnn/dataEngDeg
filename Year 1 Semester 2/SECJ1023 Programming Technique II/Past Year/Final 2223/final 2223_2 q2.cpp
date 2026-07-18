#include <iostream>
#include <string>
using namespace std;

class Vehicle{
	protected:
		string brand;
		int year;
	public:
		Vehicle(string brand="", int year=0){
			this->brand = brand;
			this->year = year;
		}
		virtual void displayDetails(){
			cout << "Brand: " << brand << endl;
			cout << "Year : " << year << endl;
		}
		virtual double calculateTax() = 0;
};

class Motorcycle : public Vehicle{
	private:
		string type;
	public:
		Motorcycle(string brand=0, int year=0, string type="") : Vehicle(brand, year){
			this->type = type;
		}
		double calculateTax(){
			return 50;
		}
		void displayDetails(){
			cout << "Motorcycle Details:" << endl;
			Vehicle::displayDetails();
			cout << "Type : " << type << endl;
			cout << "Tax  : " << calculateTax() << endl;
		}
};

class Car : public Vehicle{
	private:
		int numDoors;
	public:
		Car(string brand="", int year=0, int numDoors=0) : Vehicle(brand, year){
			this->numDoors = numDoors;
		}
		double calculateTax(){
			return 100 + numDoors * 50;
		}
		void displayDetails(){
			cout << "Car Details:" << endl;
			Vehicle::displayDetails();
			cout << "Number of Doors: " << numDoors << endl;
			cout << "Tax  : " << calculateTax() << endl;	
		}
};

class Garage{
	private:
		Vehicle *v[5];
		int numVehicles;
	public:
		Garage(){
			numVehicles = 0;
		}
		void addVehicle(Vehicle *ptr){
			v[numVehicles++] = ptr;
			if(numVehicles > 5) throw "An error occurred: The maximum number of vehicles has been reached!!\n";
		}
		void displayInfo(){
			cout << "***** Garage Details *****" << endl << endl;
			for(int i=0; i<5; i++){
				cout << i+1 << ". ";
				v[i]->displayDetails();
				cout << "-------------------------" << endl << endl;
			}
		}
};

int main(){
	Garage g;
	Vehicle *v[5];
	v[0] = new Car("Toyota", 2015, 4);
	v[1] = new Car("BMW", 2019, 2);
	v[2] = new Motorcycle("Honda", 2020, "Sport");
	v[3] = new Car("Nissan", 2018, 5);
	v[4] = new Motorcycle("Harley-Davidson", 2017, "Cruiser");
	try{
		for(int i=0; i<5; i++){
			g.addVehicle(v[i]);
		}
		g.displayInfo();
	}
	catch (const char *msg){
		cout << msg;
	}
	
	return 0;
}