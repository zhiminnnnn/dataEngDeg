#include <iostream>
#include <string>
using namespace std;

int main(){
	string name, year, title, first, last, detail;
	cout << "Enter author of the book -> ";
	getline(cin, name);
	cout << "Enter year of published -> ";
	getline(cin, year);
	cout << "Enter a book title -> ";
	getline(cin, title);
	int pos = name.find(" ");
	first = name.substr(0, pos);
	last = name.substr(pos + 1, name.length() - pos - 1);
	detail = last + "," + first + " (" + year + ") " + title;
	cout << "\nThe Formatted Book Reference:\n";
	cout << detail;
	return 0;
}