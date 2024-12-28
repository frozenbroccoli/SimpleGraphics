#include <iostream>
#include "src/Graphics/Line.h"
#include "src/Graphics/Color.h"
#include "src/Graphics/Screen.h"
#include "src/Graphics/Point.h"

int main() {
    try {
        Screen screen {2, 5};
        Color white {true};
        Point start {4, 4, white};
        Point end {14, 1, white};
        Line line {start, end, white};
        line.draw(&screen);
        screen.display();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
}
