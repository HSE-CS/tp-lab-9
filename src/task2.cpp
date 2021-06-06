// Copyright 2021 DB
#include "task2.h"

#include <thread>

void BSort(std::vector<std::string>& arr,
                bool _comp(const std::string s1, const std::string s2)) {
  std::vector<std::string> v(arr);
  std::mutex a;
  std::size_t n = v.size();
  for (std::size_t i = 0; i < n - 1; i++) {
    std::thread th([&v, &_comp, &a, &i, &n]() {
      for (std::size_t j = 0; j < n - i - 1; j++) {
        if (_comp(v[j + 1], v[j])) {
          a.lock();
          std::string temp = v[j];
          v[j] = v[j + 1];
          v[j + 1] = temp;
          a.unlock();
        }
      }
    });
    th.join();
    print(v);
  }
}

void print(std::vector<std::string>& arr) {
  for (auto x : arr) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
}
