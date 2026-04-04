#ifndef RECT_H
#define RECT_H

class Rect
{
private:
	int x, y; // The top-left corner coordinates
	int width, height;
	int color;

public:
	Rect(int, int, int, int, int);
	void draw();
};

#endif