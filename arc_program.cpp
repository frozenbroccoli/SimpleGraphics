#include <cmath>
#include "Graphics/Arc.h"

int main() {
    Screen screen {10, 50};
    Color white {true};
    Point start {70, 10};
    Point center {35, 10};
    double angle = M_PI;
    SimpleArc semicircle {center, start, angle};
    semicircle.draw(&screen, white);
    screen.display();
}
