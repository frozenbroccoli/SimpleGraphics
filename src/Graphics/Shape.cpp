#include "Shape.h"
#include "Point.h"
#include "Color.h"
#include "Screen.h"

Shape::Shape() {
	col = Color {true};
	center = Point {0, 0};
}

Shape::Shape(Point center_point, Color color) {
	center = center_point;
	col = color;
}

Point Shape::where() { return center; }

void Shape::move(Point to, Screen* screen) {
	center = to;
	draw(screen);
}

void Shape::draw(Screen* screen) {}
void Shape::rotate(int angle, Screen* screen) {}
