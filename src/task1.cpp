// Copyright 2021 Egor Buzanov

#include "../include/task1.h"

void bubbleSort(std::vector<std::string> &_array,
                std::function<bool(std::string, std::string)> _comp) {
  for (size_t i = 0; i < _array.size() - 1; i++) {
    for (size_t j = 0; j < _array.size() - i - 1; j++) {
      if (_comp(_array[j], _array[j + 1])) {
        std::swap(_array[j], _array[j + 1]);
      }
    }
  }
}

void print(const std::vector<std::string> &_array) {
  for (const auto str : _array) {
    std::cout << str << std::endl;
  }
}
