#ifndef ARC_H
#define ARC_H

#include "Point.h"
#include "Screen.h"
#include "Color.h"

class SimpleArc {
public:
    Point coc;
    int roc;
    Point start;
    double angle;

    SimpleArc() = default;
    SimpleArc(Point coc, Point start, double angle);
    ~SimpleArc() = default;
    SimpleArc copy();
    void move(int horizontal, int vertical);
    void rotate(Point pivot, double delta_angle);
    void draw(Screen* screen, Color color);
};

#endif
