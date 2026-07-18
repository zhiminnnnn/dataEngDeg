//Program 5.18
#include <iostream>
#include <string> //(a)
using namespace std;
int main(){
	string str1 = "Hello", str2 = "World", str3;
	int len;
	str3.assign(str1); //(b)
	cout << "str3 : " << str3 << endl;
	str3.append(str2); //(c)
	cout << "New str3: " << str3 << endl;
	len = str3.length(); //(d)
	cout << "The new length of str3: " << len << endl;
	str2.assign(str3.substr(0, len/2)); //(e)
	cout << "First half of the str3: " << str2 << endl;
	return 0;
}