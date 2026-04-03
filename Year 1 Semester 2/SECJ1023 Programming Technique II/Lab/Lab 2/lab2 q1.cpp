#include <iostream>
#define PI 3.142
using namespace std;

class Cone{
	private:
		double radius, height;
	public:
		void readIn(){
			cout << "Enter radius: ";
			cin >> radius;
			cout << "Enter height: ";
			cin >> height;
		}
		double baseArea() const{
			return PI * radius * radius;
		}
		double volume(double baseArea) const{
			return 1.0/3.0 * baseArea * height;
		}
		void dispOut(double volume, double baseArea){
			cout << "\n2 private data: " << endl;
			cout << "\tRadius = " << radius << endl;
			cout << "\tHeight = " << height << endl << endl;
			cout << "Output: " << endl;
			cout << "\tBase area = " << baseArea<< endl;
			cout << "\tVolume = " << volume << endl;
		}
};

int main(){
	Cone cn1;
	cn1.readIn();
	cn1.baseArea();
	cn1.volume(cn1.baseArea());
	cn1.dispOut(cn1.volume(cn1.baseArea()), cn1.baseArea());
	
	return 0;
}
