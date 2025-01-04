#include <cmath>
#include "Graphics/Polygon.h"

Polygon::Polygon(Point c, uint8_t ns, double r) {
    center = c.copy();
    num_sides = ns;
    radius = r;
    vertices = new Point[num_sides];
    sides = new Line[num_sides];
    c.move(static_cast<int>(std::round(r)), 0);
    for (int i = 0; i < num_sides; i++) {
        c.rotate(center, 2 * M_PI / num_sides);
        vertices[i] = c;
    }
    for (int i = 0; i < num_sides; i++) {
        sides[i] = Line {vertices[i], vertices[(i + 1) % num_sides]};
    }
}

Polygon::~Polygon() {
    delete[] vertices;
}

Point Polygon::where() {
    return center;
}

void Polygon::move(int h, int v) {
    center.move(h, v);
    for (int i = 0; i < num_sides; i++) {
        vertices[i].move(h, v);
        sides[i].move(h, v);
    }
}

void Polygon::move(Point to) {
    this->move(to.x - center.x, to.y - center.y);
}

void Polygon::rotate(double delta_angle) {
    for (int i = 0; i < num_sides; i++) {
        vertices[i].rotate(center, delta_angle);
        sides[i].rotate(center, delta_angle);
    }
}

void Polygon::draw(Screen* screen, Color color) {
    for (int i = 0; i < num_sides; i++) {
        sides[i].draw(screen, color);
    }
}
