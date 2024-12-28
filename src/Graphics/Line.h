#ifndef LINE_H
#define LINE_H

#include "Point.h"
#include "Color.h"
#include "Screen.h"

class Line {
private:
    int delta_x;
    int delta_y;

public:
    Point start;
    Point end;
    double length;
    double angle;
    Color color;

    Line (Point s, Point e, Color col);
    ~Line();
    void draw(Screen* screen);
    void rotate(int angle, Screen* screen);
};

#endif
