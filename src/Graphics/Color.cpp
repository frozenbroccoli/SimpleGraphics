#include "Color.h"

Color::Color() {
    value = true;
}

Color::Color(bool v) {
    value = v;
}

bool Color::get_value() {
    return value;
}
