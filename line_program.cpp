#include <iostream>
#include "src/Graphics/Line.h"
#include "src/Graphics/Color.h"
#include "src/Graphics/Screen.h"
#include "src/Graphics/Point.h"

#define PI 3.14159265359

int main() {
    try {
        Screen screen {10, 50};
        Color white {true};
        Point start {20, 5};
        Point end {20, 15};
        Line line {start, end};
        line.draw(&screen, white);
        Point pivot = line.center;
        std::cout << "center x: " << line.center.x << ", center y: " << line.center.y << std::endl;
        std::cout << "length: " << line.length << std::endl;
        Line rotated_line = line.rotate(pivot, PI / 2);
        rotated_line.draw(&screen, white);
        screen.display();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
}
