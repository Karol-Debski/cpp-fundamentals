#pragma once
#include <limits>
#include <vector>

int maxOfVector(const std::vector<int>& vec) {
    int lastMax{std::numeric_limits<int>::min()};

    for (const auto& e : vec) {
        lastMax = (e > lastMax) ? e : lastMax;
    }

    return lastMax;
}
