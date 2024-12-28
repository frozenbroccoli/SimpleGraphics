#include "Line.h"
#include "Point.h"
#include "Screen.h"
#include "Shape.h"
#include "cmath"

Line::Line(Point s, Point e, Color col) {
    start = s;
    end = e;
    color = col;
    delta_x = end.x - start.x;
    delta_y = end.y - start.y;
    length = std::sqrt(
        std::pow((delta_y), 2) + std::pow((delta_x), 2)
    );
    angle = std::atan(delta_y / delta_x);
}

Line::~Line() {}

void Line::draw(Screen* screen) {
    int steps = std::max(std::abs(delta_x), std::abs(delta_y));
    double x_increment = delta_x / steps;
    double y_increment = delta_y / steps;
    std::cout << "abs delta x: " << std::abs(delta_x) << ", abs delta y: " << std::abs(delta_y) << std::endl;
    std::cout << "x increment: " << x_increment << ", y increment: " << y_increment << std::endl;
    for (int i = 0; i < steps; ++i) {
        Point curr {
            start.x + static_cast<int>(i * x_increment), 
            start.y + static_cast<int>(i * y_increment),
            color
        };
        curr.draw(screen);
    }
}

void Line::rotate(int angle, Screen* screen) {
    /* code */
}
