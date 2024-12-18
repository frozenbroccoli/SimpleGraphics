#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>

class Screen {
    unsigned char* screen;
    int width;
    int height;
public:
    Screen(unsigned char* screen_array, int w, int h);
    friend std::ostream& operator<<(std::ostream& os, const Screen& screen);
};

#endif
