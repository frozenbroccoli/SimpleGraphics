#ifndef POINT_H
#define POINT_H

#include "Screen.h"
#include "Color.h"

class Point {
public:
	int x;
	int y;
	double r;
	double theta;
	Point();
	Point(int x_coord, int y_coord);
	Point(double r_polar, double theta_polar);
	Point rotate(Point pivot, double delta_angle);
	void draw(Screen* screen, Color color);
};

#endif
