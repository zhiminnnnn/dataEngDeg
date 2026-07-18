#include <iostream>
using namespace std;

//Program 4.31
class Rectangle {
	int width, height;
	public:
		Rectangle (int, int);
		int calculateArea ();
		friend Rectangle duplicate (Rectangle);
};

Rectangle::Rectangle(int w=0, int h=0){
	width = w;
	height = h;
}

int Rectangle::calculateArea(){
	return width * height;
}

Rectangle duplicate(Rectangle r){
	Rectangle temp;
	temp.width = r.width * 2;
	temp.height = r.height * 2;
	return temp;
}

//Program 4.4
int main () {
	Rectangle rect(10,30), rectb;
	rectb = duplicate (rect);
	cout << rectb.calculateArea();
	return 0;
}