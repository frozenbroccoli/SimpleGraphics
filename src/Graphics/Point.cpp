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

Point Point::rotate(Point pivot, double delta_angle) {
    Point at_origin {x - pivot.x, y - pivot.y};
    Point rotated_at_origin {at_origin.r, at_origin.theta + delta_angle};
    Point rotated_at_pivot {rotated_at_origin.x + pivot.x, rotated_at_origin.y + pivot.y};
    return rotated_at_pivot;
}

void Point::draw(Screen* screen, Color color) {
    screen->set_pixel(x, y, color.value);
}
