#include "src\Graphics\Circle.h"


int main() {
    Screen screen {10, 50};
    Color white {true};
    Point center {40, 25};
    int radius {20};
    Circle circle {center, radius};
    circle.draw(&screen, white);
    circle.move(10, 0);
    circle.draw(&screen, white);
    circle.move(-20, 0);
    circle.draw(&screen, white);
    screen.display();
}
