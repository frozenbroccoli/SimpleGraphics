#include <cmath>
#include "Graphics/Circle.h"

Circle::Circle(Point c, int r) {
    center = c;
    radius = r;
    Point arc_start {center.x + radius, center.y};
    perimeter = Arc {center, arc_start, 2 * M_PI};
}

Circle Circle::copy() {
    return Circle {center, radius};
}

Point Circle::where() {
    return center;
}

void Circle::move(int horizontal, int vertical) {
    center.move(horizontal, vertical);
    perimeter.move(horizontal, vertical);
}

void Circle::move(Point to) {
    perimeter.move(to.x - center.x, to.y - center.y);
    center = to;
}

void Circle::rotate(double delta_angle) {
    perimeter.rotate(center, delta_angle);
}

void Circle::draw(Screen* screen, Color color) {
    perimeter.draw(screen, color);
}
