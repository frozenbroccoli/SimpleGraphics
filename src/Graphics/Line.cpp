#include "Line.h"
#include "Point.h"
#include "Screen.h"
#include "Shape.h"
#include "cmath"

Line::Line(Point s, Point e) {
    start = s;
    end = e;
    delta_x = end.x - start.x;
    delta_y = end.y - start.y;
    length = std::sqrt(
        std::pow((delta_y), 2) + std::pow((delta_x), 2)
    );
    center = Point {
        start.x + static_cast<int>(std::round(delta_x / 2)),
        start.y + static_cast<int>(std::round(delta_y / 2))
    };
    angle = std::atan2(delta_y, delta_x);
}

Line::~Line() {
    /* code */
}

Line Line::rotate(Point pivot, double delta_angle) {
    Point new_start = start.rotate(pivot, delta_angle);
    Point new_end = end.rotate(pivot, delta_angle);
    return Line {new_start, new_end};
}

void Line::draw(Screen* screen, Color color) {
    double steps = std::max(std::abs(delta_x), std::abs(delta_y));
    double x_increment = delta_x / steps;
    double y_increment = delta_y / steps;
    Point curr;
    for (int i = 0; i < steps; i++) {
        curr.x = start.x + static_cast<int>(std::round(i * x_increment));
        curr.y = start.y + static_cast<int>(std::round(i * y_increment));
        curr.draw(screen, color);
    }
    end.draw(screen, color);
}
