#include <iostream>
using namespace std;

class BasicShape{
	protected:
		double area;
	public:
		BasicShape(){
			area = 0;
		}
		double getArea(){
			return area;
		}
		virtual void calcArea() = 0;
};

class Circle : public BasicShape{
	private:
		int centerX, centerY;
		double radius;
	public:
		Circle(int centerX=0, int centerY=0, double radius=0){
			this->centerX = centerX;
			this->centerY = centerY;
			this->radius = radius;
			calcArea();
		}
		int getCenterX(){
			return centerX;
		}
		int getCenterY(){
			return centerY;
		}
		void calcArea(){
			area = 3.14159 * radius * radius;
		}
};

class Rectangle : public BasicShape{
	private:
		int width, length;
	public:
		Rectangle(int width=0, int length=0){
			this->width = width;
			this->length = length;
			calcArea();
		}
		int getWidth(){
			return width;
		}
		int getLength(){
			return length;
		}
		void calcArea(){
			area = length * width;
		}
};

int main(){
	Circle circle(0, 0, 10);
	Rectangle rectangle(20, 30);
	BasicShape *shape[2] = {&circle, &rectangle};
	for(int i=0; i<2; i++){
		shape[i]->calcArea();
		cout << shape[i]->getArea() << endl;
	}
	return 0;
}