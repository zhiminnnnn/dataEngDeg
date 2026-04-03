#include <iostream>
using namespace std;

//Program 3.4
class FeetInches{
	private:
		int feet; 
		int inches; 
	public:
		FeetInches(int f=0, int i=0) { 
			feet = f;
			inches = i;
		}
		void setFeet(int f) { feet = f; }
		void setInches(int i) { inches = i; }
		int getFeet() const { return feet; }
		int getInches() const { return inches; }
		FeetInches(FeetInches &obj){
			feet = obj.feet;
			inches = obj.inches;
		}
		FeetInches multiply(FeetInches obj){
			obj.feet *= feet;
			obj.inches *= inches;
			return obj;
		}
};

int main(){
	FeetInches one(20, 50);
	FeetInches two(one);
	FeetInches three;
	
	three = one.multiply(two);
 	cout << one.getFeet() << endl << two.getFeet() << endl << three.getFeet() << endl;
	
	return 0;
}

