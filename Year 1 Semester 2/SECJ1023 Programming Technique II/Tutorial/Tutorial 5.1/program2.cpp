#include<iostream>
#include<string>

using namespace std;

int main()
{
	string name;
	string id;
	
	// Task 1: Allow user to enter his or her full name and id number
	cout << "Enter your full name => ";
	//________________________
	getline(cin, name);


	cout << "Enter your ID Number => ";
	//________________________
	getline(cin, id);


	// Task 2: To determine the gender from the last digit
	// Task 2a: Extract the last digit from the id
	//________________________
	string last = id.substr(id.length()-1, 1);


	// Task 2b: Convert the last digit to a number
	//________________________
	int digit = stoi(last);

	
	// Task 2c: Determine the gender such that, an odd value is male and even is female
	string gender;
	//________________________
	(digit % 2) ? (gender = "Male") : (gender = "Female");
	
	// Task 3: To extract the dob
	// Task 3a: Extract the year, month and day from the id

	string sYear  = id.substr(0,2);
	//________________________
	string sMonth = id.substr(2, 2);
	//________________________
	string sDay = id.substr(4, 2);

	// Task 3b: Convert the year, month and day to integers
	//________________________
	int year = stoi(sYear);
	//________________________
	int month = stoi(sMonth);
	//________________________
	int day = stoi(sDay);


	// Task 3c: Convert the year to be in full value form, e.g. 99 becomes 1999 and 02 becomes 2002
	//________________________
	(year <= 18) ? (year += 2000) : (year += 1900);

	
	// Task 4: Calculate the age
	//________________________
	int age = 2018 - year;

	
	// Task 5: Determine the string name for the month
	//________________________
	string MONTHS[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	string monthName = MONTHS[month-1];

	// Task 6: Using a loop, convert the name to capital letters
	//________________________
	for(int i=0; i<name.length(); i++){
		name[i] = (char)toupper(name[i]);
	}
	


	// Task 7: print all the required output
	cout << "Output: " << endl << endl;
	cout << "Name    : " << name << endl;
	cout << "ID      : " << id << endl;
	cout << "Gender  : " << gender << endl;
	cout << "Age     : " << age << " years old" << endl;
	cout << "DOB     : " << day << " " << monthName << " " << year << endl << endl;

    return 0;
}

