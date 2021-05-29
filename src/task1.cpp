#pragma once

#include "task1.h"
#include <iostream>
#include <vector>

void bubblesort(std::vector<std::string>& v,
    std::function<bool(std::string, std::string)> comparator) {
    for (unsigned int i = 0; i < v.size() - 1; ++i) {
        for (unsigned int j = 0; j < v.size() - i - 1; ++j) {
            if (comparator(v[j], v[j + 1])) {
                std::string temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}