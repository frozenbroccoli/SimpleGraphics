#include "Painter.h"

Painter::Painter(unsigned char* sc) {
    screen = sc;
}

void Painter::set_pixel(
    int bytes_per_row,
    int num_rows,
    int x,
    int y,
    bool light_up
) {
    screen += x >> 3;
    screen += bytes_per_row * num_rows;
    if (light_up) {
        (*screen) |= 0b10000000 >> (x & 7);
    } else {
        (*screen) &= ~(0b10000000 >> (x & 7));
    }
}
