#include <iostream>
#include <climits>
#include "Screen.h"

Screen::Screen(unsigned char* screen_array, int w, int h) {
    screen = screen_array;
    width = w;
    height = h;
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
    unsigned char screen_array[] {
        0b00000000, 0b00000001, 0b00000010, 
        0b00000011, 0b00000100, 0b00000101
    };
    int width {2};
    int height {3};
    Screen screen {screen_array, width, height};
    std::cout << screen;
    return 0;
}
