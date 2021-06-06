// Copyright 2021 LongaBonga
#include "task1.h"

void print(std::vector<std::string> & vec) {
  for (auto value : vec) {
    std::cout << value << ' ';
  }
  std::cout << '\n';
}


std::vector<std::string> bubbleSort(const std::vector<std::string>& vec, std::function<bool(std::string, std::string)> comparator) {
  std::vector<std::string> ans(vec);
  for (auto i = 0; i < vec.size(); i++)
    for (auto j = 0; j < vec.size() - 1; j++)
        if (comparator(ans[j], ans[j + 1])) {
            std::string buffer = ans[j];
            ans[j] = ans[j + 1];
            ans[j + 1] = buffer;
        }
  return ans;
}
