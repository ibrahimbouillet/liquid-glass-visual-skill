// Run: c++ -std=c++11 -Wall -Wextra -pedantic tests/contrast_test.cpp -o contrast_test && ./contrast_test
#include "../tools/contrast.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace liquid_glass_skill;
    const RGB8 black{0, 0, 0};
    const RGB8 white{255, 255, 255};
    const RGB8 gray{128, 128, 128};
    assert(std::abs(luminance(black)) < 1e-12);
    assert(std::abs(luminance(white) - 1.0) < 1e-12);
    assert(std::abs(contrast_ratio(black, white) - 21.0) < 1e-9);
    assert(std::abs(contrast_ratio(white, black) - 21.0) < 1e-9);
    assert(contrast_ratio(gray, black) > contrast_ratio(gray, white));
    const auto on_white = preferred_text_on(white);
    assert(on_white.r == 0 && on_white.g == 0 && on_white.b == 0);
    const auto on_black = preferred_text_on(black);
    assert(on_black.r == 255 && on_black.g == 255 && on_black.b == 255);
}
