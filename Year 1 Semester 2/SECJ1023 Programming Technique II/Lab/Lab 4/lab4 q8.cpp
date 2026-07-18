#include <iostream>
using namespace std;

class Point{
	private:
		int x, y;
	public:
		Point(int x, int y){
			this->x = x;
			this->y = y;
		}
		Point(const Point &p){
			x = p.x;
			y = p.y;
		}
		void display(){
			cout << "x = " << x << "\ty = " << y << endl;
		}
		void display(string title){
			cout << title << ": "
				 << "x = " << x << "\ty = " << y << endl;
		}
		Point operator+ (Point p){
			Point temp(0, 0);
			temp.x = x + p.x;
			temp.y = y + p.y;
			return temp;
		}
		
		friend double slope(Point p1, Point p2){
			return (p2.y - p1.y) / (p2.x - p1.x);
		}
};

int main(){
	Point p1(1, 2);
	Point p2(3, 4);
	Point p3 = p1 + p2;
	p1.display();
	p2.display();
	p3.display("Third point");
	cout << "Slope = " << slope(p1, p2);
	return 0;
}