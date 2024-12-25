#ifndef LINE_H
#define LINE_H

#include "Shape.h"
#include "Point.h"

class Line: public Shape {
public:
    Point start;
    Point end;
    int length;
    double angle;

    Line();
    Line(Point center, Color color, int len, double ang);
    Line (Point start, Point end, Color color);
    ~Line();
    void draw(Screen* screen);
    void rotate(int angle, Screen* screen);
};

#endif
