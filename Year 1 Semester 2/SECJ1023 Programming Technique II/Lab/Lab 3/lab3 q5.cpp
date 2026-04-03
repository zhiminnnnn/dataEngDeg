#include <iostream>
using namespace std;

class Point{
	private:
		double x, y;
	public:
		Point(double x=0, double y=0){
			this->x = x;
			this->y = y;
		}
		void shift(double x_amount, double y_amount){
			x += x_amount;
			y += y_amount;
		}
		void set_x(double x){
			this->x = x;
		}
		void set_y(double y){
			this->y = y;
		}
		double get_x(){
			return x;
		}
		double get_y(){
			return y;
		}
};

int main(){
	Point p1(1, 2), p2;
	p2.set_x(3);
	p2.set_y(4);
	
	cout << "Coordinates before moving: p1 (" << p1.get_x() << ", " << p1.get_y() << ")" << endl;
	cout << "Coordinates before moving: p2 (" << p2.get_x() << ", " << p2.get_y() << ")" << endl;
	cout << endl;
	
	p1.shift(5, 6);
	p2.shift(7, 8);
	
	cout << "Coordinates after moving : p1 (" << p1.get_x() << ", " << p1.get_y() << ")" << endl;
	cout << "Coordinates after moving : p2 (" << p2.get_x() << ", " << p2.get_y() << ")" << endl;
	
	return 0;
}
