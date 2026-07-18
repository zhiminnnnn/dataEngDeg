// Programming Technique II (SCSJ1023)
// Tutorial 1: Procedural Programming (PP) vs. Object-Oriented Programming (OOP)
// Program 3: Using OOP
// Use the following coordinates: (1, 2) and (3, 4) for Circle 1 and 2 to test your code
// The distance and slope between these two circle centres are 2.83 and 1 respectively

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// ! Task 1: Define a class to represent the structure of a circle.
// !         It consists of information the circle's centre coordinate. 
// !         The operations that the circle should have.
class Circle{
	private:
		int x, y;
	public:
		Circle(int x, int y){
			this->x = x;
			this->y = y;
		}
		int getX(){
			return x;
		}
		int getY(){
			return y;
		}
};

int main()
{
	// ! Task 2: Create a circle object with specified information
	Circle c1(1,2), c2(3,4);

	// ! Task 3: Calculate the distance and slope between two circle centres
	double d = sqrt(pow(c2.getX() - c1.getX(), 2) + pow(c2.getY() - c1.getY(), 2));
	double s = (double) (c2.getY() - c1.getY()) / (c2.getX() - c1.getX());

	// ! Task 4: Display the distance and slope between two circle centres
	cout << fixed << setprecision(2);
	cout << "Distance between two circle centres: " << d << endl;
	cout << "Slope between two circle centres: " << s << endl;

	return 0;
}
