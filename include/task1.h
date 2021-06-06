// Copyright 2021 DB
#ifndef INCLUDE_TASK1_H_
#define INCLUDE_TASK1_H_

#include <utility>
#include <vector>
#include <iostream>
#include <string>

template <class T>
void bSort(std::vector<std::string>& arr, T comp) {
  int ar = arr.size();
  for (int i = 0; i < ar; i++) {
    for (int j = 0; j < ar - 1; j++) {
      if (comp(arr[j + 1], arr[j])) {
        std::swap(arr[j], arr[j + 1]);
      }
    }
  }
}
#endif  //  INCLUDE_TASK1_H_
