// Copyright 2021 MalininDmitry

#ifndef INCLUDE_TASK2_H_
#define INCLUDE_TASK2_H_
#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <mutex>
#include <thread>

template<typename T>
void sorttask2(std::vector<T> &arr,
               const std::function<bool(T, T)>&
               comp, std::mutex &mtx) {
    
    for (int i = 0; i < arr.size() - 1; ++i) {
        std::thread th([&arr, &comp, &i, &mtx]() {
            for (int j = 0; j < arr.size() - i - 1; ++j) {
                if (comp(arr[j], arr[j + 1])) {
                    mtx.lock();
                    T temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    mtx.unlock();
                }
            }
        });
        printarr(arr, std::ref(mtx));
        th.join();
    }
    printarr(arr, std::ref(mtx));
    
}
template<typename T>
void printarr(std::vector<T> &arr, std::mutex &mtx) {
    mtx.lock();
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    mtx.unlock();
}
#endif  // INCLUDE_TASK2_H_
