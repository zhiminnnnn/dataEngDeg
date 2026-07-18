//Program 5.19
#include <iostream>
#include <string> //(a)
using namespace std;
int main(){
	string firstname = "Abu", lastname = "Bakar";
	string fullname;
	fullname.assign(firstname + " " + lastname); //(b)
	fullname.append(","); //(c)
	fullname.append("Dr"); //(d)
	cout << fullname << endl;
	fullname.replace(10, 2, "Prof Madya"); //(e)
	cout << fullname << endl;
	fullname.erase(14, 6); //(f)
	cout << fullname << endl;
	fullname.insert(10, "Associate "); //(g)
	cout << fullname << endl;
	return 0;
}