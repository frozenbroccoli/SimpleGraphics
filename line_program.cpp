#include <iostream>
#include <cmath>
#include "src/Graphics/Line.h"
#include "src/Graphics/Color.h"
#include "src/Graphics/Screen.h"
#include "src/Graphics/Point.h"

int main() {
	try {
		Screen screen {10, 50};
		Color white {true};
		Point start {20, 5};
		Point end {20, 15};
		Line line {start, end};
		std::cout << "angle: " << line.angle << std::endl;
		line.draw(&screen, white);
		Point pivot = line.center;
		line.rotate(pivot, -M_PI / 2);
		std::cout << "angle: " << line.angle << std::endl;
		line.draw(&screen, white);
		line.move(0, -5);
		std::cout << "angle: " << line.angle << std::endl;
		line.draw(&screen, white);
		screen.display();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}    
}
