// Programming Technique II (SCSJ1023)
// Tutorial 1: Procedural Programming (PP) vs. Object-Oriented Programming (OOP)
// Program 1: Using PP
// Use the following coordinates: (1, 2) and (3, 4) for Circle 1 and 2 to test your code
// The distance and slope between these two circle centres are 2.83 and 1 respectively

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// ! Task 1: Define a function to calculate the distance between two circle centres.
double dis(int x1, int y1, int x2, int y2){
	return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

// ! Task 2: Define a function to calculate the slope between two circle centres.
double slp(int x1, int y1, int x2, int y2){
	return (y2-y1) / (x2-x1);
}


int main()
{
	int x1, y1; //centre coordinate for Circle 1
	int x2, y2; //centre coordinate for Circle 2

	// ! Task 3: Ask the user to enter the centre coordinates of two circles
	cout << "Enter Circle 1 coordinate: ";
	cin >> x1 >> y1;
	cout << "Enter Circle 2 coordinate: ";
	cin >> x2 >> y2;

	// ! Task 4: Calculate the distance and slope between two circle centres
	double distance = dis(x1, y1, x2, y2);
	double slope = slp(x1, y1, x2, y2);

	// ! Task 5: Display the distance and slope between two circle centres
	cout << fixed << setprecision(2);
	cout << "Distance between two circle centres: " << distance << endl;
	cout << "Slope between two circle centres: " << slope << endl;

	return 0;
}
