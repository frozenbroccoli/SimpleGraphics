#include "Point.h"
#include "cmath"

Point::Point() {
    x = 0;
    y = 0;
    r = 0.0;
    theta = 0.0;
}

Point::Point(int x_coord, int y_coord) {
    x = x_coord;
    y = y_coord;
    r = std::sqrt(std::pow(x, 2) + std::pow(y, 2));
    theta = std::atan2(y, x);
}

Point::Point(double r_polar, double theta_polar) {
    r = r_polar;
    theta = theta_polar;
    x = std::round(r * std::cos(theta));
    y = std::round(r * std::sin(theta));
}

void Point::reconstruct(Point point) {
    x = point.x;
    y = point.y;
    r = point.r;
    theta = point.theta;
}

Point Point::copy() {
    return Point {x, y};
}

void Point::move(int h, int v) {
    Point moved {x + h, y + v};
    this->reconstruct(moved);
}

void Point::rotate(double delta_angle) {
    Point rotated {r, theta + delta_angle};
    this->reconstruct(rotated);
}

void Point::rotate(Point pivot, double delta_angle) {
    Point copy = this->copy();
    copy.move(-pivot.x, -pivot.y);
    copy.rotate(delta_angle);
    copy.move(pivot.x, pivot.y);
    this->reconstruct(copy);
}

void Point::draw(Screen* screen, Color color) {
    screen->set_pixel(x, y, color.value);
}
