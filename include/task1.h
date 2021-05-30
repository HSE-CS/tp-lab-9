// Copyright 2021 Kuznetsov Mikhail
#ifndef INCLUDE_TASK1_H_
#define INCLUDE_TASK1_H_
#include <string>
#include <vector>
#include <iostream>
#include <functional>

template<class T>
void bubbleSort(std::vector<std::string> &_arr, T _comp) {
  std::size_t n = _arr.size();
  for (std::size_t i = 0; i < n; i++) {
    for (std::size_t j = 0; j < n - 1; j++) {
      if (_comp(_arr[j + 1], _arr[j])) {
        std::swap(_arr[j], _arr[j + 1]);
      }
    }
  }
}

void print(std::vector<std::string> &_arr);
#endif  //  INCLUDE_TASK1_H_
