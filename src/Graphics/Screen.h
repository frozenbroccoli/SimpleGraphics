#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>

class Screen {
    int width;
    int height;
    unsigned char* screen;

public:
    Screen(int w, int h);
    ~Screen();
    void display();
    void set_pixel(
        int x,
        int y,
        bool light_up
    );
    friend std::ostream& operator<<(std::ostream& os, const Screen& screen);
};

#endif
