#pragma once
#include <vector>

int addEven(const std::vector<int>& numbers) {
    int sum{0};

    for(const auto& e : numbers)
    {
        sum += ( (e % 2) == 0 ) ? e : 0;     
    }

    return sum;
}
