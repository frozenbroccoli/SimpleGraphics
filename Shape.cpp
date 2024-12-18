#include <Shape.h>
#include <Point.h>
#include <Color.h>

class Shape {
	Point center;
	Color col;
	unsigned char* screen;

public:
	Point where() { return center; }
	void move(Point to) {
		center = to;
		draw();
	}
	virtual void draw();
	virtual void rotate(int angle);
};
