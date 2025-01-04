#include <iostream>
#include <cmath>
#include "Graphics/Line.h"
#include "Graphics/Color.h"
#include "Graphics/Screen.h"
#include "Graphics/Point.h"

int main() {
	try {
		Screen screen {10, 50};
		Color white {true};
		Point start {20, 5};
		Point end {20, 25};
		Line line {start, end};
		line.draw(&screen, white);
		Point pivot = line.center;
		line.rotate(pivot, -M_PI / 6);
		line.draw(&screen, white);
		line.rotate(pivot, -M_PI / 6);
		line.draw(&screen, white);
		line.rotate(pivot, -M_PI / 6);
		line.move(0, -5);
		line.draw(&screen, white);
		screen.display();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}    
}
