#include <iostream>
#include <string>
using namespace std;

int main(){
	string name;
	string s[10] = {"Muhamad Husin, A123456", 
					"Nor Asma, A156782", 
					"Raja Kumar, A187623", 
					"Muhamad Ali, A123908", 
					"Ali Shah, A145234", 
					"Nor Nadia, A128734", 
					"Siti Sarah, A120945", 
					"Siti Kahadijah, A154237", 
					"Syed Azman, A276456", 
					"Chong Wei, A156278"};
	cout << "Searching Student's Info\n";
	cout << "------------------------\n";
	cout << "Enter the name or partial name you would like to search for: ";
	getline(cin, name);
	cout << "\nSearch results:\n";
	for(int i=0; i<10; i++){
		if(s[i].find(name) != string::npos)
			cout << s[i] << endl;
	}
	return 0;
}