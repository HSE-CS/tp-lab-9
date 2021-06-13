// Copyright 2021 S
#include "task1.h"

void print(const std::vector<std::string>& vector) {
    for (auto string : vector) {
        std::cout << string << ", ";
    }
    std::cout << '\n';
}

std::vector<std::string> bubbleSort(const std::vector<std::string>& vector,
        std::function<bool(std::string, std::string)> comp) {
    std::vector<std::string> copyVector(vector);
    for (int i = 0; i < vector.size(); i++)
        for (int j = 0; j < vector.size() - 1; j++)
            if (comp(copyVector[j], copyVector[j + 1])) {
                std::string buff = copyVector[j];
                copyVector[j] = copyVector[j + 1];
                copyVector[j + 1] = buff;
            }
    return copyVector;
}
