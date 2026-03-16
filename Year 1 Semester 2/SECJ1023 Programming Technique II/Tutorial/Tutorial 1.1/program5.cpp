// Programming Technique II (SECJ1023)
// Revision and Level Test of Procedural Programming
// Program 5: Date conversion 2
// Name: Cheng Zhi Min (A25CS0050)
// Date: 16/3/2026

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char month[4];
    int day;
    int year;

    cout << "Enter your DOB (Mmm dd yyyy) => ";
    cin >> month >> day >> year;
    
    string mon = month;
    int m;
    
	if (mon == "Jan")
	    m = 1;
	else if (mon == "Feb")
	    m = 2;
	else if (mon == "Mar")
	    m = 3;
	else if (mon == "Apr")
	    m = 4;
	else if (mon == "May")
	    m = 5;
	else if (mon == "Jun")
	    m = 6;
	else if (mon == "Jul")
	    m = 7;
	else if (mon == "Aug")
	    m = 8;
	else if (mon == "Sep")
	    m = 9;
	else if (mon == "Oct")
	    m = 10;
	else if (mon == "Nov")
	    m = 11;
	else if (mon == "Dec")
	    m = 12;
	else
	    cout << "Invalid month" << endl;
	
    cout << endl;
    cout << "Your Date of Birth is " << day << "-" << m << "-" << year << endl;

    system("pause");

    return 0;
}
