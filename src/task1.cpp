// Copyright 2021 Schenikova

#include "task1.h"

std::vector<std::string> BubbleSort(const std::vector<std::string>& array,
    std::function<bool(std::string, std::string)> comp) {
    std::vector<std::string> arr(array);
    for (int i = 0; i < arr.size() - 1; ++i) {
        for (int j = 0; j < arr.size() - i - 1; ++j) {
            if (comp(arr[j], arr[j + 1])) {
                std::swap(arr[j], arr[j + 1]);
                // std::string temp = arr[j];
                // arr[j] = arr[j + 1];
                // arr[j + 1] = temp;
            }
        }
    }
    return arr;
    }

void print(std::vector<std::string> words) {
    for (std::string a : words) {
        std::cout  << a << " ";
    }
    std::cout << std::endl << std::endl;
}

