// Copyright 2021 valvarl

#ifndef INCLUDE_TASK1_H_
#define INCLUDE_TASK1_H_

#include <functional>

template<typename T, int N>
void bubble_sort(T (*arr)[N], const std::function<bool(T, T)>& comp) {
    for (int i = 0; i < N; i++) {
        for (int j = N-1; j > i; j--) {
            if (comp((*arr)[j-1], (*arr)[j])) {
                std::swap((*arr)[j-1], (*arr)[j]);
            }
        }
    }
}

#endif  // INCLUDE_TASK1_H_
