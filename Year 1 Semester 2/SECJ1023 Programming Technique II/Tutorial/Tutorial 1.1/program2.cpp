// Programming Technique II (SECJ1023)
// Revision and Level Test of Procedural Programming
// Program 2: Find the largest number
// Name: Cheng Zhi Min (A25CS0050)
// Date: 16/3/2026

#include <iostream>

using namespace std;

//Define a function that determines the largest number from two numbers
int largest(int a, int b){
	if (a>b)
		return a;
	else
		return b;
}

int main()
{
    int a, b, c, d;

    cout << "Please enter the four numbers => ";
    cin >> a >> b >> c >> d;
    
    int max1, max2, max;
    
    max1 = largest(a, b);
    max2 = largest(c, d);
    max = largest(max1, max2);
    

    cout << endl;
    cout << "The largest value is " << max << endl;

    system("pause");

    return 0;
}
