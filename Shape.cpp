#include "Shape.h"
#include "Point.h"
#include "Color.h"

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
