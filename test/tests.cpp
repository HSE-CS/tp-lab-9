// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "task1.h"
#include "task2.h"
#include "task3.h"

TEST(task1, t_1) {
  std::vector<std::string> vec = {"up", "dont", "give"};
  bSort(vec, [](std::string& s1, std::string& s2) { return s1 < s2; });
  std::vector<std::string> expect = {"dont", "give", "up"};
  EXPECT_EQ(expect, vec);
}
