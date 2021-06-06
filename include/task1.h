// Copyright 2021 GN
#ifndef INCLUDE_TASK1_H_
#define INCLUDE_TASK1_H_

#include <vector>
#include <string>
#include <iostream>
#include <utility>
template<class T>
void bubbleSort(std::vector<std::string>& arr, T comp) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (comp(arr[j + 1], arr[j])) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}
#endif  //  INCLUDE_TASK1_H_
