// Programming Technique II (SECJ1023)
// Revision and Level Test of Procedural Programming
// Program 1: Simple calculator
// Name: Cheng Zhi Min (A25CS0050)
// Date: 16/3/2026

#include <iostream>

using namespace std;

int main()
{
	double num1, num2;
	char op;
	double result;
	cout << "Enter arithmetic operation => ";
	cin >> num1 >> op >> num2;
	
	switch (op){
		case '+':
			result = num1 + num2;
			break;
		case '-':
			result = num1 - num2;
			break;
		case '*':
			result = num1 * num2;
			break;
		case '/':
			result = num1 / num2;
			break;
		default:
			cout << "Invalid operation." << endl;
	}
	cout << "Result = " << result << endl;

    return 0;
}
