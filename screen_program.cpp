#include <iostream>
#include "src/Graphics/Screen.h"

int main() {
    try {
        int width {3};
        int height {5};
        Screen screen {width, height};
        std::cout << "\nOriginal screen: " << std::endl;
        screen.display();
        screen.set_pixel(0, 0, true);
        std::cout << "\nUpdated Screen: " << std::endl;
        screen.display();
        return 0;
    } catch (std::runtime_error& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return -1;
    }
}
