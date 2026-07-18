#include <iostream>
using namespace std;

class Address{
	private:
		string registrar;
		string country;
	public:
		Address(){
			registrar = "";
			country = "";
		}
		void set(string r, string c){
			registrar = r;
			country = c;
		}
		string getRegistrar(){
			return registrar;
		}
		string getCountry(){
			return country;
		}
};

class Ship{
	private:
		string name;
		string yearMade;
		Address *address;
	public:
		Ship(){
			name = "";
			yearMade = "";
			address = new Address();
		}
		void read(){
			cout << "<<< Enter the information of the ship >>>" << endl << endl;
			cout << "Ship Name: ";
			getline(cin, name);
			cout << "Year Built: ";
			getline(cin, yearMade);
			cout << endl;
			cout << "The address the ship was registered: " << endl;
			string r, c;
			cout << "Registrar Office: ";
			getline(cin, r);
			cout << "Country: ";
			getline(cin, c);
			address->set(r, c);
			cout << endl;
		}
		void print(){
			cout << "Ship Name: " << name << endl;
			cout << "Year Built: " << yearMade << endl;
			cout << "Registered at: " << endl;
			cout << "\t" << address->getRegistrar() << ", " << address->getCountry() << endl << endl;
		}
};

void menu(int &choice){
	cout << "======== MENU ========" << endl;
	cout << "1. Add a ship" << endl;
	cout << "2. Display ships" << endl;
	cout << "3. Exit" << endl << endl;
	cout << "Choose an operation => ";
	cin >> choice;
	cin.ignore();
	cout << endl;
}

void shipList(int count, Ship *s){
	cout << "<<< Inventory of ships >>>" << endl << endl;
	cout << "Total ship: " << count << endl << endl;
	cout << "==== Ship List ====" << endl << endl;
	for(int i=0; i<count; i++){
		s[i].print();
	}
	return;
}

int main(){
	int choice;
	menu(choice);
	const int MAX = 100;
	int count = 0;
	Ship *s = new Ship [MAX];
	do{
		switch (choice){
			case 1:
				s[count].read();
				count ++;
				break;
			case 2:
				shipList(count, s);
				break;
		}
		menu(choice);
	}while (choice == 1 || choice == 2);
	return 0;
}