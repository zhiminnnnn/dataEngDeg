#include <iostream>
#include "Rect.h"
#include <graphics.h>
using namespace std;

Rect::Rect(int _x, int _y, int _width, int _height, int _color)
	{
		x = _x;
		y = _y;
		width = _width;
		height = _height;
		color = _color;
	}

void Rect::draw()
	{
		setfillstyle(SOLID_FILL, color);
		bar(x, y, x + width, y + height);
	}