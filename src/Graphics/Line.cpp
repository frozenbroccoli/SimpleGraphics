#include "Graphics/Line.h"
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

void Line::reconstruct(Line line) {
    start = line.start;
    end = line.end;
    center = line.center;
    length = line.length;
    angle = line.angle;
    delta_x = line.delta_x;
    delta_y = line.delta_y;
}

Line Line::copy() {
    return Line {start, end};
}

void Line::move(int h, int v) {
    start.move(h, v);
    end.move(h, v);
    Line moved {start, end};
    this->reconstruct(moved);
}

void Line::rotate(Point pivot, double delta_angle) {
    start.rotate(pivot, delta_angle);
    end.rotate(pivot, delta_angle);
    Line rotated {start, end};
    this->reconstruct(rotated);
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
