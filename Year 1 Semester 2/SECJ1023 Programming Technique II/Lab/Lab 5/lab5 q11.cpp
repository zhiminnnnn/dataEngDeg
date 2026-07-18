#include <iostream>
#include <string>
using namespace std;

string phoneFormat(string &s){
	s.insert(0, "+");
	s.insert(4, "-");
	s.insert(9, "-");
	return s;
}

int main(){
	string s;
	cout << "Enter your handphone no. -> ";
	getline(cin, s);
	cout << "Your formatted handphone no. -> " << phoneFormat(s) << endl;
	return 0;
}