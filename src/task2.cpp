// Copyright 2021 me
#include<iostream>
#include "../include/task2.h"

void task2(std::vector<std::string>& toSort,
           std::function<bool(std::string, std::string)>& comp, bool &isWork,
           std::mutex& mtx) {
  isWork = true;
  for (size_t i = 0; i < toSort.size() - 1; ++i) {
    mtx.lock();
   // std::cout << "sorting\n";
    for (size_t j = i + 1; j < toSort.size(); ++j) {
      if (comp(toSort[i], toSort[j])) {
        swap(toSort[i], toSort[j]);
      }
    }
    mtx.unlock();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
  isWork = false;
}

void print_vector(std::vector<std::string>& toPrint, bool &isWork, std::mutex& mtx) {
  while (isWork) {
   // std::cout << "\nPrinting\n";
    mtx.lock();
    for (auto i : toPrint) {
      std::cout << "\"" << i << "\""
                << " ";
    }
    std::cout << "\n";
    mtx.unlock();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}
