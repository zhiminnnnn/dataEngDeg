#include <iostream>
#include <cmath>
using namespace std;

// Task 1: Complete the definition of class Date.
class Date 
{
	private: 
		string desc;
		int day, mon, yr;
	public:	
		Date(){
			desc = "";
			day = 0;
			mon = 0;
			yr = 0;
		}
		Date(string desc, int day, int mon, int yr){
			this->desc = desc;
			this->day = day;
			this->mon = mon;
			this->yr = yr;
		}
		int getDay(){
			return day;
		}
		int getMon(){
			return mon;
		}
		int getYr(){
			return yr;
		}
		Date operator- (const Date &right){
			Date temp;
			temp.day = abs(day - right.day);
			temp.mon = abs(mon - right.mon);
			temp.yr = abs(yr - right.yr);
			return temp;
		}
		friend istream &operator>> (istream &strm, Date &obj){
			cout << "Enter your date (day, month, year): ";
			strm >> obj.day >> obj.mon >> obj.yr;
			return strm;
		}
		friend ostream &operator<< (ostream &strm, const Date &obj){
			cout << obj.desc << ": "
				 << obj.day << "-"
				 << obj.mon << "-"
				 << obj.yr << endl;
			return strm;
		}
		friend void displayDiff(Date, Date);
};

// Task 2: The following function is partialy given. 
// The function is meant to print the difference between two dates.
// Complete the code of the function.
void displayDiff(Date d1, Date d2) 
{
	cout << "The difference: ";
	Date temp;
	temp = d1 - d2;
	if(temp.yr == 0){
		if(temp.mon == 0){
			cout << temp.day << " day(s)";
		}
		else{
			cout << temp.mon << " months(s)";
		}
	}
	else{
		cout << temp.yr << " year(s)";
	}
	cout << endl << endl;
}

int main()
{
	// Task 3: Create an array to hold three(3) dates and initialize 
	// the description of each date with specified values.
	Date d[3];
	d[0] = Date("SBT", 0, 0, 0);
	d[1] = Date("Test", 0, 0, 0);
	d[2] = Date("Final", 0, 0, 0);
	
	// Task 4: Using a loop and an appropriate functions(s), enter the values
	// of day, month and year from the keyboard for the array
	for(int i=0; i<3; i++){
		cin >> d[i];
	}
	
	// Task 5: Create two objects named date1 and date2 with the specified data.
	Date date1("TODAY", 5, 3, 2018);
	Date date2("Date of birth", 23, 11, 1999);
	
	// Task 6: Using an appropriate function and another loop, print all the dates 
	// and the difference between date1 and other dates.
	cout << date1 << endl << date2;
	displayDiff(date1, date2);
	for(int i=0; i<3; i++){
		cout << d[i];
		displayDiff(date1, d[i]);
	}
	return 0;
}