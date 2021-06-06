  // Copyright 2021 kisozinov

#include "task1.h"

std::vector<std::string> bubbleSort(const std::vector<std::string> &vec,
    std::function<bool(std::string, std::string)> comparator) {
    sort(vec.begin(), vec.end(), comparator);
    return vec;
}

void print(std::vector<std::string> vec) {
    std::cout << "[";
    for (auto str : vec) {
        std::cout << "'" << str << "', ";
    }
    std::cout << "]\n" << std::endl;
}
