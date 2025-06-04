#include "vectorFunctions.hpp"
#include <iostream>

std::vector<std::shared_ptr<int>> generate(const int count) {
    std::vector<std::shared_ptr<int>> vec;

    for (int i = 0; i < count; ++i) {
        vec.push_back(std::make_shared<int>(i));
    }

    return vec;
}

void print(const std::vector<std::shared_ptr<int>>& vec) {
    for (const auto& ele : vec) {
        std::cout << *ele << std::endl;
    }
}

void add10(std::vector<std::shared_ptr<int>>& vec) {
    for (const auto& ele : vec) {
        if (ele != nullptr) {
            *ele += 10;
        }
    }
}

void sub10(int* num) {
    if (num != nullptr) {
        *num -= 10;
    }
}

void sub10(std::vector<std::shared_ptr<int>>& vec) {
    for (const auto& ele : vec) {
        if (ele != nullptr) {
            sub10(ele.get());
        }
    }
}