#include "Point.h"

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(int x_coord, int y_coord) {
    x = x_coord;
    y = y_coord;
}

int Point::get_x() {
    return x;
}

int Point::get_y() {
    return y;
}
