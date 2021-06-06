// Copyright 2021 valvarl

#ifndef INCLUDE_TASK2_H_
#define INCLUDE_TASK2_H_


#include <functional>
#include <mutex>
#include <thread>


template<typename T, int N>
void step_print(T (*arr)[N], const bool*, std::mutex& mtx);

template<typename T, int N>
void bubble_sort(T (*arr)[N], const std::function<bool(T, T)>& comparator,
        bool*, std::mutex& mtx);

#endif  // INCLUDE_TASK2_H_
