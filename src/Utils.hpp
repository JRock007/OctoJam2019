#pragma once

// Get distance between two coordinates
static float getMagnitude(const float x1, const float y1, const float x2, const float y2) {
    return std::sqrtf(std::powf(x1 - x2, 2) + std::powf(y1 - y2, 2));
}
