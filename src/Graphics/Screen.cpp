#include <iostream>
#include <climits>
#include "Screen.h"

Screen::Screen(int w, int h) {
    width = w;
    height = h;
    screen = new unsigned char[width * height] {0b00000000};
}

Screen::~Screen() {
    delete[] screen;
}

void Screen::set_pixel(
    int x,
    int y,
    bool light_up
) {
    int right_shift = x >> 3;
    int down_shift = width * y;

    if (right_shift >= width || y >= height) {
        throw std::runtime_error("Index out of bounds of screen size");
    }

    if (light_up) {
        (screen[right_shift + down_shift]) |= 0b10000000 >> (x & 7);
    } else {
        (screen[right_shift + down_shift]) &= ~(0b10000000 >> (x & 7));
    }
}

void Screen::display() {
    std::cout << *this;
}

std::ostream& operator<<(std::ostream& os, const Screen& screen) {
    for (int y = screen.height - 1; y >= 0; y--) {
        for (int x = 0; x < screen.width; x++) {
            for (int bit_count = CHAR_BIT - 1; bit_count >= 0; --bit_count) {
                os << ((screen.screen[y * screen.width + x] >> bit_count) & 0b00000001);
            }
        }
        os << std::endl;
    }
    return os;
}
