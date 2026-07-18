//Program 5.6
#include <iostream>
#include <string> //error
using namespace std;
int main()
{ 
	string myCar = "Proton";
	cout << "Enter type of car: ";
	string userCar;
	getline(cin, userCar);  //error
 
	if (userCar == "Honda")
		cout << "You have enter a Honda car.\n";
	else if(userCar == "Toyota")
		cout << "Hello Toyota car.\n";
	else if (userCar != myCar)
		cout << "Your dream car is.\t" << userCar;
	else 
		cout << "Oh it is your car \t" << myCar;
 
	return 0; 
}