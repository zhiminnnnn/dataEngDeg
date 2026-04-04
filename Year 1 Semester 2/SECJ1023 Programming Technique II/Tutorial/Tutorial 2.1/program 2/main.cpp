#include <iostream>
#include "Rect.h"
#include <graphics.h>
using namespace std;

int main()
{
	int screenWidth = getmaxwidth();
	int screenHeight = getmaxheight();
	initwindow(screenWidth, screenHeight, "Tutorial 2");

	// * ---------------------------------------------------------------------------------------------
	// * Task 3: Create some Rect objects:
	// *         1). a blue rectangle with the dimension of 200 x 250 and its top-left corner is positioned at  (300,300)
	// *         2). a yellow square with the side length of 150 and its top-left corner is positioned at origin
	// * ---------------------------------------------------------------------------------------------

	Rect r(300, 300, 200, 250, COLOR(0, 0, 255));
	Rect s(0, 0, 150, 150, YELLOW);

	// * ---------------------------------------------------------------------------------------------
	// * Task 3: Display the rectangle and square
	// * ---------------------------------------------------------------------------------------------
	r.draw();
	s.draw();
	getch();

	getch();
	return 0;
}
