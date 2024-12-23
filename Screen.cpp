#include <iostream>
#include <climits>
#include "Screen.h"

Screen::Screen(unsigned char* screen_array, int w, int h) {
    screen = screen_array;
    width = w;
    height = h;
}

void Screen::set_pixel(
    int x,
    int y,
    bool light_up
) {
    if ((x >> 3) >= width || y >= height) {
        throw std::runtime_error("Out of screen dimensions");
    }

    int right_shift = x >> 3;
    int down_shift = width * y;

    if (light_up) {
        (screen[down_shift + right_shift]) |= 0b10000000 >> (x & 7);
    } else {
        (screen[down_shift + right_shift]) &= ~(0b10000000 >> (x & 7));
    }
}

std::ostream& operator<<(std::ostream& os, const Screen& screen) {
    for (int y = 0; y < screen.height; y++) {
        for (int x = 0; x < screen.width; x++) {
            for (int bit_count = CHAR_BIT - 1; bit_count >= 0; --bit_count) {
                os << ((screen.screen[y * screen.width + x] >> bit_count) & 1);
            }
            if (x < screen.width - 1) {
                os << ',';
            }
        }
        os << std::endl;
    }
    return os;
}

int main() {
    try {
        unsigned char screen_array[] {
            0b00000000, 0b00000000, 0b00000000, 
            0b00000000, 0b00000000, 0b00000000
        };
        int width {2};
        int height {3};
        std::cout << "Original screen: " << std::endl;
        Screen screen {screen_array, width, height};
        std::cout << screen;
        std::cout << "\nUpdated screen: " << std::endl;
        screen.set_pixel(15, 1, true);
        std::cout << screen;
        return 0;
    } catch (std::runtime_error& e) {
        std::cout << "Exception: " << e.what() << std::endl;
        return -1;
    }
}
