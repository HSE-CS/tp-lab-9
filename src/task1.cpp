// Copyright 2021 SoDa

#include "task1.h"
#include <fstream>
#include <iostream>

void buble_sort(std::vector<std::string>& vect, std::function<bool(std::string, std::string)> comp) {
    int size = vect.size();
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (comp(vect[j], vect[j + 1])) {
                std::swap(vect[j], vect[j + 1]);
            }
        }
    }
}

void print_vct(std::vector<std::string>& vect) {
    for (auto word : vect) {
        std::cout << word << ' ';
    }
    std::cout << std::endl;
}