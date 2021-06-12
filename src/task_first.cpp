// Copyright 2021 SoDa

#include "../include/task_first.h"
#include <fstream>
#include <iostream>


void print_vct(std::vector<std::string> vect) {
    for (auto word : vect) {
        std::cout << word << ' ';
    }
    std::cout << std::endl;
}

void bubbleSort(std::vector<std::string>& vect,
    std::function<bool(std::string, std::string)> comp) {
    int size = vect.size();
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (comp(vect[j], vect[j + 1])) {
                std::swap(vect[j], vect[j + 1]);
            }
        }
    }
}

template<class T>
void bubbleSortT(std::vector<std::string>& vect, T comp) {
    int n = vect.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (comp(vect[j + 1 ], vect[j])) {
                std::swap(vect[j], vect[j + 1]);
            }
        }
    }
}