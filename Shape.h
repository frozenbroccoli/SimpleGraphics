#include <Point.h>
#include <Color.h>

class Shape {
	Point center;
	Color col;
	unsigned char* screen;
public:
	Point where();	
	void move(Point to);
	virtual void draw();
	virtual void rotate(int angle);	
};
