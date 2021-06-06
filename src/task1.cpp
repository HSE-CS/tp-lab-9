//  Copyright 2021 Nikita Naumov
#include "../include/task1.h"

void printVector(std::vector<std::string> vector) {
    for (auto obj: vector) {
        std::cout << obj << std::endl;
    }
};

void stringBubbleSort(std::vector<std::string>& strVector,
                      std::function<bool(std::string, std::string)> f) {
    for (size_t i = 0; i < strVector.size() - 1; ++i) {
        for (size_t j = 0; j < strVector.size() - i - 1; ++j) {
            if (f(strVector[j], strVector[j+1])) {
                std::swap(strVector[j], strVector[j+1]);
            }
        }
    }
}
