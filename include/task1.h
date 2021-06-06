// Copyright 2021 MalininDmitry

#ifndef INCLUDE_TASK1_H_
#define INCLUDE_TASK1_H_
#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include "task1.cpp"

template<typename T>
void sorttask(std::vector<T> &arr,
              const std::function<bool(T, T)>& comp) {
    for (int i = 0; i < arr.size()-1; i++) {
        for (int j = 0; j < arr.size() - i-1; j++) {
            if (comp(arr[j] , arr[j+1])) {
                T a = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = a;
            }
        }
    }
}
#endif  // INCLUDE_TASK1_H_
