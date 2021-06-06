// Copyright 2021 VA
#ifndef INCLUDE_TASK2_H_
#define INCLUDE_TASK2_H_
#include<vector>
#include<functional>
#include<iostream>
#include<algorithm>
#include<mutex>
#include <string>

std::mutex m;

void printArr(std::vector<std::string> arr) {
    int length = arr.size();
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void Sort2(std::vector<std::string> arr, 
    std::function<bool(std::string, std::string)> comp) {
    int length = arr.size();
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            m.lock();
            if (comp(arr[i], arr[j])) {
                std::swap(arr[i], arr[j]);
                printArr(arr);
            }
            m.unlock();
        }
    }
}
#endif  // INCLUDE_TASK2_H_
