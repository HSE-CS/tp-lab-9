// Copyright 2021 me
#include "../include/task1.h"

template <class T>
void swap(T &a, T &b) {
  T buff = a;
  a = b;
  b = buff;
}

void bubble_sort(std::vector<std::string> &toSort,
                 std::function<bool(std::string, std::string)> &comp) {
  for (size_t i = 0; i < toSort.size() - 1; ++i) {
    for (size_t j = i + 1; j < toSort.size(); ++j) {
      if (comp(toSort[i], toSort[j])) {
        swap(toSort[i], toSort[j]);
      }
    }
  }
}

void print_vector(std::vector<std::string> &toPrint) {
  for (auto i : toPrint) {
    std::cout << '"' << i << "\"; ";
  }
  std::cout << "\n";
}
