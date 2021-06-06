// Copyright 2021 alexgiving

#include "task2.h"
#include <thread>

void bubbleSort(std::vector<std::string>& arr,
                bool comp(const std::string& s1, const std::string& s2)) {
  std::vector<std::string> vector(arr);
  std::mutex a;
  for (size_t i = 0; i < vector.size() - 1; ++i) {
    std::thread th([&vector, &comp, &a, &i]() {
      for (size_t j = 0; j < vector.size() - i - 1; ++j)
        if (comp(vector[j + 1], vector[j])) {
          a.lock();
          std::swap(vector[j], vector[j + 1]);
          a.unlock();
        }
    });
    th.join();
    print(vector);
  }
}

void print(std::vector<std::string> const & arr) {
  for (const auto& elem : arr)
    std::cout << elem << "\t";
  std::cout << std::endl;
}

void print(std::vector<std::string> const& arr, const std::string& sep) {
  for (size_t i = 0; i < arr.size() - 1; ++i)
    std::cout << arr[i] << sep << ' ';
  std::cout << arr[arr.size() - 1] << std::endl;
}
