#include <cmath>
#include "Graphics/Polygon.h"

int main() {
    Screen screen {10, 50};
    Color white {true};
    Point center {40, 25};
    uint8_t num_sides {4};
    double radius {10.0};
    Polygon polygon {center, num_sides, radius};
    polygon.draw(&screen, white);
    polygon.move(0, 10);
    polygon.draw(&screen, white);
    polygon.move(20, -10);
    polygon.rotate(M_PI / 4);
    polygon.draw(&screen, white);
    screen.display();
    std::cout << "Num sides: " << (int)polygon.num_sides << std::endl;
}
