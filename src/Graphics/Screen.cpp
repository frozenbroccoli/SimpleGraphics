#include <iostream>
#include <climits>
#include "Graphics/Screen.h"

Screen::Screen(int w, int h) {
    if (w <= 0 || h <= 0) {
        throw std::invalid_argument("Screen dimensions must be positive");
    }

    width = w;
    height = h;
    screen = new unsigned char[width * height] {0b00000000};
    hdc = GetDC(NULL);
    if (!hdc) {
        throw std::runtime_error("Failed to get DC");
    }

    bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bmi.bmiHeader.biWidth = width * 8;
    bmi.bmiHeader.biHeight = height;
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biBitCount = 32;
    bmi.bmiHeader.biCompression = BI_RGB;
    bmi.bmiHeader.biSizeImage = 0;
    bmi.bmiHeader.biXPelsPerMeter = 0;
    bmi.bmiHeader.biYPelsPerMeter = 0;
    bmi.bmiHeader.biClrUsed = 0;
    bmi.bmiHeader.biClrImportant = 0;

    h_bitmap = CreateDIBSection(hdc, &bmi, DIB_RGB_COLORS, (void**)&framebuffer, NULL, 0);
    if (!h_bitmap) {
        throw std::runtime_error("Failed to create DIB section");
    }
}

Screen::~Screen() {
    if (h_bitmap) {
        DeleteObject(h_bitmap);
    }
    if (hdc) {
        ReleaseDC(NULL, hdc);
    }
    delete[] screen;
}

void Screen::set_pixel(
    int x,
    int y,
    bool light_up
) {
    int right_shift = x >> 3;
    int down_shift = width * y;

    if (x < 0 || x >= width << 3 || y < 0 || y >= height) {
        throw std::runtime_error("Index out of bounds of screen size");
    }

    int byte_index = right_shift + down_shift;
    int bit_index = x & 7;

    if (light_up) {
        screen[byte_index] |= 0b10000000 >> bit_index;
        framebuffer[y * (width * 8) + x] = 0xFFFFFF;
    } else {
        screen[byte_index] &= ~(0b10000000 >> bit_index);
        framebuffer[y * (width * 8) + x] = 0x000000;
    }
}

void Screen::display() {
    HDC mem_dc = CreateCompatibleDC(hdc);
    if (!mem_dc) {
        throw std::runtime_error("Failed to create compatible DC");
    }

    if (!SelectObject(mem_dc, h_bitmap)) {
        DeleteDC(mem_dc);
        throw std::runtime_error("Failed to select bitmap into memory DC");
    }

    if (!BitBlt(hdc, 0, 0, width * 8, height, mem_dc, 0, 0, SRCCOPY)) {
        DeleteDC(mem_dc);
        throw std::runtime_error("Failed to blit to screen");
    }

    DeleteDC(mem_dc);
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
