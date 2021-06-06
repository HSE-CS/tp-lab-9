// Copyright 2021 alexgiving

#ifndef INCLUDE_TASK_1_H_
#define INCLUDE_TASK_1_H_

#include <vector>
#include <string>
#include <iostream>
#include <utility>  // For swap

void print(std::vector<std::string> const & arr);
void print(std::vector<std::string> const & arr, const std::string& separator);

template<class T>
void bubbleSort(std::vector<std::string> & arr, T comp) {
  for (size_t i = 0; i < arr.size(); i++)
    for (size_t j = 0; j < arr.size() - 1; j++)
      if (comp(arr[j + 1], arr[j]))
        std::swap(arr[j], arr[j + 1]);
}

#endif  // INCLUDE_TASK_1_H_
