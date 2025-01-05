#include "Graphics/Arc.h"
#include "cmath"

SimpleArc::SimpleArc(Point center_of_curvature, Point st, double ang) {
    coc = center_of_curvature;
    start = st;
    angle = ang;
    roc = std::sqrt(
        std::pow((coc.y - start.y), 2) + std::pow((coc.x - start.x), 2)
    );
}

SimpleArc SimpleArc::copy() {
    return SimpleArc {coc, start, angle};
}

void SimpleArc::move(int horizontal, int vertical) {
    coc.move(horizontal, vertical);
    start.move(horizontal, vertical);
}

void SimpleArc::rotate(Point pivot, double delta_angle) {
    coc.rotate(pivot, delta_angle);
    start.rotate(pivot, delta_angle);
}

void SimpleArc::draw(Screen* screen, Color color) {
    int steps = static_cast<int>(std::round(roc * angle));
    double increment = angle / steps;
    for (int i = 0; i < steps; i++) {
        Point cursor = start.copy();
        cursor.rotate(coc, i * increment);
        cursor.draw(screen, color);
    }
}
