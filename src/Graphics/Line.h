#ifndef LINE_H
#define LINE_H

#include "Point.h"
#include "Color.h"
#include "Screen.h"

class Line {
private:
    double delta_x;
    double delta_y;
    void reconstruct(Line line);

public:
    Point start;
    Point end;
    Point center;    
    double length;
    double angle;

    Line (Point s, Point e);
    ~Line();
    void rotate(Point pivot, double delta_angle);
    void draw(Screen* screen, Color color);
};

#endif
