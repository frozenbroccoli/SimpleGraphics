#include "Shape.h"
#include "Point.h"
#include "Color.h"
#include "Screen.h"

Shape::Shape(Point center_point, Color color, Screen screen_obj) {
	center = center_point;
	col = color;
	screen = screen_obj;
}

Point Shape::where() { return center; }

void Shape::move(Point to) {
	center = to;
	draw();
}

void Shape::draw() {
	// Draw a shape
};

void Shape::rotate(int angle) {
	// Rotate a shape
};
