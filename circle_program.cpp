#include "Graphics/Circle.h"


int main() {
    Screen screen {100, 800};
    Color white {true};
    Point center {400, 500};
    int radius {200};
    Circle circle {center, radius};
    circle.draw(&screen, white);
    screen.display();
    circle.move(50, 0);
    circle.draw(&screen, white);
    screen.display();
    circle.move(-100, 0);
    circle.draw(&screen, white);
    screen.display();
    
}
