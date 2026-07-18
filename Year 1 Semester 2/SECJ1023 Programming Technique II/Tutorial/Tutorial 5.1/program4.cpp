#include<iostream>
#include<string>
#include<cmath>

using namespace std;

// Task 1: Define the function lowercase that converts a string to lower case
string lowercase(string s)
{
	//_____________________
	for(int i=0; i<s.length(); i++){
		s[i] = (char)tolower(s[i]);
	}
	return s;
}

// Task 2: Define the function textToNumber that converts a number in word to its integer value
int textToNumber(string txt)
{
	//_____________________
	if(txt == "one")
		return 1;
	if(txt == "two")
		return 2;
	if(txt == "three")
		return 3;
	if(txt == "four")
		return 4;
	if(txt == "five")
		return 5;
	return -1;
}

int main()
{
	// Task 3a: Read user input
	string text;
	cout <<"What is: ";
	//_____________________
	getline(cin, text);
	
	// Task 3b: Convert the user input to lower case
	//_____________________
	text = lowercase(text);
	
	int len = text.length();
	
	// Task 4: Extract words of the first and second operands as well as the operator
	//_____________________
	int pos1 = text.find(' ');
	int pos2 = text.find(' ', pos1 + 1);
	string operand1 = text.substr(0, pos1);
	string operand2 = text.substr(pos2 + 1, len - pos2 - 1);
	string operation = text.substr(pos1 + 1, pos2 - pos1 - 1);
	
	// Task 5: Convert the operands from words to integers
	//_____________________
	int value1 = textToNumber(operand1);
	int value2 = textToNumber(operand2);
	
	// Task 6: Perform the arithmetic calculation accordingly, i.e., addition or subtraction
	int result;
	//_____________________
	if(operation == "plus")
		result = value1 + value2;
	else
		result = value1 - value2;

	// Task 7: Convert the result from integer to word
	//_____________________
	string sResult;
	switch (result){
		case -1:
			sResult = "negative one";
			break;
		case -2:
			sResult = "negative two";
			break;
		case -3:
			sResult = "negative three";
			break;
		case -4:
			sResult = "negative four";
			break;
		case 0:
			sResult = "zero";
			break;
		case 1:
			sResult = "one";
			break;
		case 2:
			sResult = "two";
			break;
		case 3:
			sResult = "three";
			break;
		case 4:
			sResult = "four";
			break;
		case 5:
			sResult = "five";
			break;
		case 6:
			sResult = "six";
			break;
		case 7:
			sResult = "seven";
			break;
		case 8:
			sResult = "eight";
			break;
		case 9:
			sResult = "nine";
			break;
		case 10:
			sResult = "ten";
			break;
	}
	
	// Task 8: Print the answer
	//_____________________
	cout << "Answer: " << operand1 << " " << operation << " " << operand2 << " is " << sResult;
	return 0;
}
