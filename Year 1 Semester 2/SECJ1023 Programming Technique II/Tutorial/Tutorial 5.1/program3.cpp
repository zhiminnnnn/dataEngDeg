#include<iostream>
#include<string>

using namespace std;

int main()
{
    string expression;
	string operand1, operand2, operation;
    double value1, value2, result;
    
    // Task 1: Read the string of arithmetic expression and put it into the variable "expression"
	cout <<"Enter an arithmetic expression, e.g. 20 + 30  => ";
	//_____________________________________________
	getline(cin, expression);
	
    // Task 2: Extract the operator and both operands from "expression" and 
	//           put them into the variables "operation", "operand1", and "operand2", accordingly
		
    // ___________________________;
    int findSpace = expression.find(" ");
    operand1 = expression.substr(0, findSpace);
    operand2 = expression.substr(findSpace+3, expression.length()-findSpace+3);
    operation = expression.substr(findSpace+1, 1);
    
	// Task 3:  Convert the string operands to numbers. 
	//            Put the numbers into variables "value1" and "value2", respectively
	
	// ___________________;
	value1 = stoi(operand1);
	value2 = stoi(operand2);
    
    // Task 4: Determine the type of operation (i.e., either +, -, *, or / ) and perform the arithmetic calculation accordingly.
    //          Put the result of the calculation into the variable "result".
    if(operation.compare("+") == 0)
    	result = value1 + value2;
	else if(operation.compare("-") == 0)
    	result = value1 - value2;
    else if(operation.compare("x") == 0)
    	result = value1 * value2;
    else
    	result = value1 / value2;

    cout << "The value of the expression " << expression << " is " << result << endl << endl;
    return 0;
}