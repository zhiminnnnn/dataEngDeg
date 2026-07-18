#include <iostream>
#include <string>
using namespace std;

int main(){
	string s = "Programming is a subject!";
	cout << s << endl;
	cout << s.insert(17, "good ") << endl;
	cout << s.replace(12, 13, "re") << endl;
	return 0;
}