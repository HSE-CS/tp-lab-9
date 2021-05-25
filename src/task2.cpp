// Copyright 2021 valvarl

#include <iostream>
#include <zconf.h>
#include "task2.h"


std::function comp{
        [](const std::string &a, const std::string &b) {
            return a > b;
        }
};


template<typename T, int N>
void step_print(T (*arr)[N], const bool *work, std::mutex& mtx) {
    while (*work) {
        mtx.lock();
        for (int k{ 0 }; k < N; k++) std::cout << (*arr)[k] << ' ';
        std::cout << std::endl;
        mtx.unlock();
        usleep(50000);
    }
}


template<typename T, int N>
void bubble_sort(T (*arr)[N], const std::function<bool(T, T)>& comparator,
                 bool *work, std::mutex& mtx) {

    for (int i = 0; i < N; i++) {
        usleep(50000);
        mtx.lock();
        for (int j = N-1; j > i; j--) {
            if (comparator((*arr)[j - 1], (*arr)[j])) {
                std::swap((*arr)[j-1], (*arr)[j]);
            }
        }
        mtx.unlock();
    }
    *work = false;
}
