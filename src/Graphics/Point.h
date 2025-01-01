#ifndef POINT_H
#define POINT_H

#include "Screen.h"
#include "Color.h"

class Point {
private:
	void reconstruct(Point point);
public:
	int x;
	int y;
	double r;
	double theta;
	
	Point() = default;
	Point(int x_coord, int y_coord);
	Point(double r_polar, double theta_polar);
	~Point() = default;
	Point copy();
	void move(int horizontal, int vertical);
	void rotate(double delta_angle);
	void rotate(Point pivot, double delta_angle);
	void draw(Screen* screen, Color color);
};

#endif
