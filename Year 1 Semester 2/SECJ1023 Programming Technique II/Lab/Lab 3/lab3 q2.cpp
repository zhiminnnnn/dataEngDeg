#include <iostream>
#include <cmath>
using namespace std;

class Compute{
	private:
		double a, b, c, discriminant;
		double calcDiscriminant(){
			return b*b - 4*a*c;
		}
	public:
		Compute(double a, double b, double c){
			this->a = a;
			this->b = b;
			this->c = c;
		}
		double positive_root(){
			return (-1 * b + sqrt(calcDiscriminant())) / (2 * a);
		}
		double negative_root(){
			return (-1 * b - sqrt(calcDiscriminant())) / (2 * a);
		}
};

//Program 3.2
int main(){
	double a, b, c;
	cout << "Enter coefficients a, b and c: ";
	cin >> a >> b >> c;
	
	// (a)Pass arguments a, b, c to the constructor
	Compute c1(a, b, c);
	
	cout << "The roots of the quadratic equation are x = ";
	
	// (b)Execute function members to display the value x1
	cout << c1.positive_root();
	cout << ", ";
	
	// (c)Execute function members to display the value x2
	cout << c1.negative_root() << endl;
	
	return 0;
}
