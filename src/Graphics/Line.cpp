#include "Line.h"
#include "Point.h"
#include "Screen.h"
#include "Shape.h"

Line::Line() {
    center = Point {0, 0};
    col = true;
    length = 1;
    angle = 0.0;
}

Line::Line(Point center_point, Color color, int len, double ang) {
    center = center_point;
    col = color;
    length = len;
    angle = ang;
}

Line::Line(Point s, Point e, Color color) {
    start = s;
    end = e;
    col = color;
}

Line::~Line() {}

void Line::draw(Screen* screen) {
    int half_length = length >> 1;
    for (int i = -half_length; i < half_length; i++) {
        screen->set_pixel(center.get_x() + i, center.get_y(), col.get_value());
    }
}

void Line::rotate(int angle, Screen* screen) {}
