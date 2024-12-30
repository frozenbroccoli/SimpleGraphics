#include "Shape.h"
#include "Point.h"
#include "Color.h"
#include "Screen.h"

Shape::Shape() {
	center = Point {0, 0};
}

Shape::Shape(Point c) {
	center = c;
}

Point Shape::where() { return center; }

void Shape::move(Point to) {}

void Shape::draw(Screen* screen) {}

void Shape::rotate(double delta_angle) {}
