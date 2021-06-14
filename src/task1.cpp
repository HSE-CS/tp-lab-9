// Copyright 2021 Panina Polina
#include "task1.h"

#include <iostream>
#include <string>
#include <utility>
#include <vector>

template <class T>
void bubble_sort(std::vector<std::string>& array, T comp) {
  int n = array.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (comp(array[j + 1], array[j])) { std::swap(array[j], array[j + 1]); }
    }
  }
}
