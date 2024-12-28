#include "Point.h"

Point::Point() {
    Color white = {true};
    x = 0;
    y = 0;
    color = white;
}

Point::Point(int x_coord, int y_coord, Color col) {
    x = x_coord;
    y = y_coord;
    color = col;

}

void Point::draw(Screen* screen) {
    screen->set_pixel(x, y, color.get_value());
}
