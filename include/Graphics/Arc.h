#ifndef ARC_H
#define ARC_H

#include "Point.h"
#include "Screen.h"
#include "Color.h"

class Arc {
public:
    Point coc;
    int roc;
    Point start;
    double angle;

    Arc() = default;
    Arc(Point coc, Point start, double angle);
    ~Arc() = default;
    Arc copy();
    void move(int horizontal, int vertical);
    void rotate(Point pivot, double delta_angle);
    void draw(Screen* screen, Color color);
};

#endif
