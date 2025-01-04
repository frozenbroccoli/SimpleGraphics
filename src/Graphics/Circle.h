#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include "Arc.h"

class Circle : public Shape {
private:
    Arc perimeter;

public:
    Point center;
    int radius;

    Circle() = default;
    Circle(Point center, int radius);
    Circle copy();
    Point where();
    void move(Point to);
    void move(int horizontal, int vertical);
    void rotate(double delta_angle);
    void draw(Screen* screen, Color color);
};

#endif
