#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <cstdint>
#include <windows.h>

class Screen {
private:
    unsigned char* screen;
    uint32_t* framebuffer;
    HDC hdc;
    BITMAPINFO bmi;
    HBITMAP h_bitmap;

public:
    int width;
    int height;
    Screen(int w, int h);
    ~Screen();
    void display();
    void set_pixel(int x, int y, bool light_up);
    friend std::ostream& operator<<(std::ostream& os, const Screen& screen);
};

#endif
