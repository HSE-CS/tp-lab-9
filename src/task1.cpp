//  Copyright 2021 Nikita Naumov
#include "../include/task1.h"

void stringBubbleSort(std::vector<std::string>& strVector, std::function<bool(std::string, std::string)> f) {
    for (size_t i = 0; i < strVector.size() - 1; ++i) {
        for (size_t j = i + 1; j < strVector.size(); ++j) {
            if (f(strVector[i], strVector[j])) {
                std::swap(strVector[i], strVector[j]);
            }
        }
    }
}