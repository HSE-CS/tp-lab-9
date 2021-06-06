// Copyright 2021 LongaBonga
#include "task2.h"
#include "task1.h"

std::vector<std::string> bubbleSortParallel(std::vector<std::string>& vec, std::function<bool(std::string, std::string)> comparator) {
  std::vector<std::string> ans(vec);
  std::mutex a;
  for (auto i = 0; i < vec.size(); i++) {
    std::thread stream([&ans, &comparator, &a, &i]() {
      for (auto j = 0; j < ans.size() - 1; j++)
          if (comparator(ans[j], ans[j + 1])) {
              a.lock();
              std::string buffer = ans[j];
              ans[j] = ans[j + 1];
              ans[j + 1] = buffer;
              a.unlock();
          }
    });

    stream.join();
    print(ans);
  }
}
