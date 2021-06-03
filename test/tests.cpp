// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>

#include <algorithm>
#include <cstdlib>
#include <functional>

#include "task1.h"
#include "task2.h"
#include "task3.h"

TEST(bubble_sort, int) {
  std::vector<int> v;
  std::srand(10);
  for (int i = 0; i < 100; ++i) {
    v.push_back(std::rand() % 10000);
  }
  bubble_sort(
      v.begin(), v.end(),
      (std::function<bool(const int &, const int &)>)[](
          const int &a, const int &b) { return a > b; });
  ASSERT_TRUE(std::is_sorted(v.begin(), v.end()));
}
