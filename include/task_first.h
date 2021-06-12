// Copyright 2021 Bogomazov

#ifndef INCLUDE_TASK1_H_
#define INCLUDE_TASK1_H_

#include <string>
#include <vector>
#include <utility>
#include <iterator>
#include <iostream>
#include <functional>


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

void print_vct(std::vector<std::string>);

void bubbleSort(std::vector<std::string>& vect,
    std::function<bool(std::string, std::string)> comp);

#endif  // INCLUDE_TASK1_H_
