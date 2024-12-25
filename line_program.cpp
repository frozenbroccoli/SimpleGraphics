#include <iostream>
#include "src/Graphics/Line.h"
#include "src/Graphics/Color.h"
#include "src/Graphics/Screen.h"
#include "src/Graphics/Point.h"

int main() {
    try {
        Screen screen {2, 5};
        Point center {8, 2};
        Color white {true};
        int length {5};
        double angle {0.0};
        Line line {center, white, length, angle};
        line.draw(&screen);
        screen.display();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
}
