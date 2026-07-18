//Program 9.1
#include <iostream>
#include <string>
using namespace std;
int main(){
	int donuts, milk;
	double dpg;
	string msg;
	cout << "Enter number of donuts:\n";
	cin >> donuts;
	cout << "Enter number of glasses of milk:\n";
	cin >> milk;
	try{
		if (milk <= 0)
		{
			msg = to_string(donuts) + " donuts, and No Milk!\n" + "Go buy some milk.\n";
		 	throw msg; 
		}
		dpg = donuts/static_cast<double>(milk);
		cout << donuts << " donuts.\n"
	 		 << milk << " glasses of milk.\n"
	 		 << "You have " << dpg
			 << " donuts for each glass of milk.\n";
	}
	catch(string msg){
		cout << msg << endl;
	}
	cout << "End of program.\n";
	return 0;
}