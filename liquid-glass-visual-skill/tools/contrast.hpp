// MIT License. Optional standalone C++11+ color math helper.
// Input is an OPAQUE sRGB color, NOT a screenshot/backdrop sampler.
// Always evaluate final composited pixels before claiming contrast compliance.
#pragma once
#include <cmath>
#include <cstdint>

namespace liquid_glass_skill {
struct RGB8 {
    std::uint8_t r, g, b;
};

inline double linear_channel(std::uint8_t v) noexcept {
    const double s = static_cast<double>(v) / 255.0;
    return s <= 0.04045 ? s / 12.92 : std::pow((s + 0.055) / 1.055, 2.4);
}

inline double luminance(RGB8 c) noexcept {
    return 0.2126 * linear_channel(c.r) +
           0.7152 * linear_channel(c.g) +
           0.0722 * linear_channel(c.b);
}

inline double contrast_ratio(RGB8 a, RGB8 b) noexcept {
    const double x = luminance(a), y = luminance(b);
    return (x > y ? x + 0.05 : y + 0.05) /
           (x > y ? y + 0.05 : x + 0.05);
}

// A starting choice only. A patterned/translucent surface needs more samples.
inline RGB8 preferred_text_on(RGB8 opaque_backdrop) noexcept {
    const RGB8 black{0, 0, 0}, white{255, 255, 255};
    return contrast_ratio(opaque_backdrop, black) >=
                   contrast_ratio(opaque_backdrop, white)
               ? black : white;
}
} // namespace liquid_glass_skill
