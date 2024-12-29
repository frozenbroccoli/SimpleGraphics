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
        Point end {35, 15};
        Line line {start, end};
        line.draw(&screen, white);
        Point pivot {30, 5};
        Line rotated_line = line.rotate(pivot, PI / 6);
        rotated_line.draw(&screen, white);
        screen.display();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
}
