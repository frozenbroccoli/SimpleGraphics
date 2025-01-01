#ifndef POLYGON_H
#define POLYGON_H

#include <cstdint>
#include "Point.h"
#include "Line.h"
#include "Color.h"
#include "Screen.h"
#include "Shape.h"

class Polygon : public Shape {
private:
    Point* vertices;
    Line* sides;
    
public:
    Point center;
    uint8_t num_sides;
    double radius;

    Polygon(Point center, uint8_t num_sides, double radius);
    ~Polygon();
    Point where() override;
    void move(int horizontal, int vertical) override;
    void move(Point to) override;
    void rotate(double delta_angle) override;
    void draw(Screen* screen, Color color) override;
};

#endif
