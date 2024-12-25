#ifndef POINT_H
#define POINT_H

class Point {
	int x;
	int y;

public:
	Point();
	Point(int x_coord, int y_coord);
	int get_x();
	int get_y();
};

#endif
