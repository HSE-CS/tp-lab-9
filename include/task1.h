// Copyright 2021 VA
#ifndef INCLUDE_TASK1_H_
#define INCLUDE_TASK1_H_
#include<vector>
#include<functional>
#include<iostream>
#include<algorithm>
#include<utility>
#include <string>

void Sort(const std::vector<std::string>& arr, 
    std::function<bool(std::string, std::string)> comp) {
    int length = arr.size();
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (comp(arr[i], arr[j]))
                std::swap(arr[i], arr[j]);
        }
    }
}

void printArr1(std::vector<std::string> arr) {
    int length = arr.size();
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}
#endif  // INCLUDE_TASK1_H_
