// Copyright 10.06.21 DenisKabanov

#ifndef INCLUDE_TASK1_H_
#define INCLUDE_TASK1_H_

#include <iostream>
#include <utility>
#include <string>
#include <vector>

template <class T>
void bubble(std::vector<std::string>& arr, T comp) {
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (comp(arr[j + 1], arr[j]))
                std::swap(arr[j], arr[j + 1]);
        }
    }
}

void print(std::vector<std::string>& arr);

#endif  //  INCLUDE_TASK1_H_
