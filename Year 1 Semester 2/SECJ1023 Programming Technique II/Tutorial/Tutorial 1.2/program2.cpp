// Programming Technique II (SCSJ1023)
// Tutorial 1: Procedural Programming (PP) vs. Object-Oriented Programming (OOP)
// Program 2: Using PP with struct
// Use the following coordinates: (1, 2) and (3, 4) for Circle 1 and 2 to test your code
// The distance and slope between these two circle centres are 1.41 and 1 respectively

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// ! Task 1: Define a struct data type to hold information about a circle
struct Circle{
	int a, b;
};

// ! Task 2: Define a function to calculate the distance between two circle centres.
double dis(Circle c1, Circle c2){
	return sqrt(pow(c2.a - c1.a, 2) + pow(c2.b - c1.b, 2));
}

// ! Task 3: Define a function to calculate the slope between two circle centres.
double slp(Circle c1, Circle c2){
	return (c2.b - c1.b) / (c2.a - c1.a);
}

int main()
{
	// ! Task 4: Define a circle with specified information from the struct data type
	Circle c1, c2;
	c1.a = 1;
	c1.b = 2;
	c2.a = 3;
	c2.b = 4;

	// ! Task 5: Calculate the distance and slope between two circle centres
	double distance = dis(c1, c2);
	double slope = slp(c1, c2);
	
	// ! Task 6: Display the distance and slope between two circle centres
	cout << fixed << setprecision(2);
	cout << "Distance between two circle centres: " << distance << endl;
	cout << "Slope between two circle centres: " << slope << endl;

	return 0;
}
