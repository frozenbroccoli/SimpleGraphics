#include <conio.h>
#include "Graphics/Circle.h"


int main() {
    Screen screen {100, 800};
    Color white {true};
    Point center {400, 500};
    int radius {200};
    Circle circle {center, radius};
    circle.draw(&screen, white);
    screen.display();
    std::cout << "Press any key to proceed..." << std::endl;
    _getch();
    circle.move(50, 0);
    circle.draw(&screen, white);
    screen.display();
    std::cout << "Press any key to proceed..." << std::endl;
    _getch();
    circle.move(-100, 0);
    circle.draw(&screen, white);
    screen.display();
    std::cout << "Press any key to proceed..." << std::endl;
    _getch();

}
