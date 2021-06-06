// Copyright 2021 alexgiving

#include "task1.h"

void print(std::vector<std::string> const & arr) {
     for (const auto& elem : arr)
         std::cout << elem << '\t';
     std::cout << std::endl;
}

void print(std::vector<std::string> const & arr, const std::string& separator) {
  for (size_t i = 0; i < arr.size() - 1; ++i)
    std::cout << arr[i] << separator << ' ';
  std::cout << arr[arr.size() - 1] << std::endl;
}
