// Copyright 2021 valvarl

#ifndef INCLUDE_TASK1_H_
#define INCLUDE_TASK1_H_

#include <functional>

template<typename T, int N>
void bubble_sort(T (*arr)[N], const std::function<bool(T, T)>& comp);

#endif  // INCLUDE_TASK1_H_
